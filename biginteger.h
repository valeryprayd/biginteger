// BigInteger : a class for long arithmetic akin to those found in other languages. It supports all basic operations
// (+ - * / %), comparisons, negative numbers, and stream output. C++11 or higher is required for compilation.
//
// This class does not represent a library or any part of a library. If you wish to use it, just copy and paste
// it into your code, or use it as a whole. You are free to use and modify it with or without any reference to
// its creator.

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <utility>
#include <string>

class BigInteger {
public:

    // 1. Construction

    BigInteger() : isNegative{0}, digits{0} {}

    template <typename T>
    explicit BigInteger(T value) : isNegative(value < 0), digits()  {
        parseInt(value < 0 ? -value : value);
    }

    // 2. Comparisons

    bool operator == (const BigInteger& other) const {
        return (isNegative == other.isNegative) && (digits == other.digits);
    }

    template <typename T>
    bool operator == (const T& value) const {
        return *this == BigInteger(value);
    }

    bool operator != (const BigInteger& other) const {
        return !(*this == other);
    }

    template <typename T>
    bool operator != (const T& value) const {
        return *this != BigInteger(value);
    }

    // 3. Addition and subtraction

    const BigInteger operator - () const {
        BigInteger tmp = *this;
        tmp.isNegative = !tmp.isNegative;
        tmp.normalizeZero();
        return tmp;
    }

    const BigInteger operator + (const BigInteger& other) const;

    template <typename T>
    const BigInteger operator + (const T& value) const {
        return *this + BigInteger(value);
    }

    const BigInteger operator - (const BigInteger& other) const;

    template <typename T>
    const BigInteger operator - (const T& value) const {
        return *this - BigInteger(value);
    }

    // 4. Multiplication and division

    const BigInteger operator * (const BigInteger& other) const;

    template <typename T>
    const BigInteger operator * (const T& value) const {
        return *this * BigInteger(value);
    }

    // 5. Miscellanious

    const unsigned int operator [] (std::size_t i) const { return digits[i]; }

    unsigned int operator [] (std::size_t i) { return digits[i]; }

    std::string toString() const {
        std::string rep(' ', digits.size());
        std::transform(digits.rbegin(), digits.rend(), rep.begin(), [](unsigned int arg){
            return (char)('0' + arg);
        });
        if (isNegative) rep = '-' + rep;
        return rep;
    }

private:
    template <typename T>
    void parseInt(T value) {
        if (value == 0) digits.push_back(0);
        else
            while (value != 0) {
                digits.push_back(value % 10);
                value /= 10;
            }
    }

    static const std::vector<char>& smallerSeq(const std::vector<char>& lhs, const std::vector<char>& rhs);

    static const std::vector<char>& greaterSeq(const std::vector<char>& lhs, const std::vector<char>& rhs);

    static std::vector<char> addDigits(const std::vector<char>& lhs, const std::vector<char>& rhs);

    // First memeber of the pair indicates whether returned value is negative, second contains digits of the result.
    static std::pair<bool, std::vector<char>>
    subtractDigits(const std::vector<char>& lhs, const std::vector<char>& rhs);

    // Use recursive Karatsuba algorithm to multiply two sequences of digits. Sequences are assumend to be of the
    // same size.
    static std::vector<char> multiplyDigits(const std::vector<char>& lhs, const std::vector<char>& rhs);

    static void removeLeadingZeroes(std::vector<char>& digits) {
        digits.erase(
            std::find_if_not(
                digits.rbegin(),
                digits.rend(),
                std::bind2nd(std::equal_to<char>(), 0)).base(),
            digits.end()
        );
        if (digits.empty()) digits.push_back(0);
    }

    static void addLeadingZeroes(std::vector<char>& digits, std::size_t zeroes) {
        if (zeroes == 0) return;
        digits.resize(digits.size() + zeroes);
    }

    static void shiftUp(std::vector<char>& digits, std::size_t zeroes) {
        std::vector<char> newDigits(zeroes + digits.size(), char(0));
        std::copy(digits.begin(), digits.end(), std::next(newDigits.begin(), zeroes));
        digits = newDigits;
    }

    void normalizeZero() {
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    bool isNegative;

    std::vector<char> digits;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 1. Comparisons

template <typename T>
bool operator == (const T& value, const BigInteger& bigInteger) {
    return bigInteger == value;
}

template <typename T>
bool operator != (const T& value, const BigInteger& bigInteger) {
    return bigInteger != value;
}

const std::vector<char>& BigInteger::smallerSeq(const std::vector<char>& lhs, const std::vector<char>& rhs) {
    if (lhs.size() < rhs.size()) return lhs;
    if (lhs.size() > rhs.size()) return rhs;
    for (int i = lhs.size() - 1; i >= 0; --i) {
        if (lhs[i] < rhs[i]) return lhs;
        if (lhs[i] > rhs[i]) return rhs;
    }
    return rhs;
}

const std::vector<char>& BigInteger::greaterSeq(const std::vector<char>& lhs, const std::vector<char>& rhs) {
    if (lhs.size() < rhs.size()) return rhs;
    if (lhs.size() > rhs.size()) return lhs;
    for (int i = lhs.size() - 1; i >= 0; --i) {
        if (lhs[i] < rhs[i]) return rhs;
        if (lhs[i] > rhs[i]) return lhs;
    }
    return rhs;
}

// 2. Addition and subtraction

template <typename T>
const BigInteger operator + (const T& value, const BigInteger& bigInteger) {
    return bigInteger + value;
}

template <typename T>
const BigInteger operator - (const T& value, const BigInteger& bigInteger) {
    return BigInteger(value) - bigInteger;
}

const BigInteger BigInteger::operator + (const BigInteger& other) const {

    BigInteger sum;
    if (isNegative == other.isNegative) {
        sum.digits = addDigits(digits, other.digits);
        sum.isNegative = isNegative;
    }
    else {
        auto result = subtractDigits(
            isNegative ? other.digits : digits,
            isNegative ? digits : other.digits);
        sum.isNegative = result.first;
        sum.digits = result.second;
    }

    sum.normalizeZero();
    return sum;
}

const BigInteger BigInteger::operator - (const BigInteger& other) const {

    BigInteger difference;
    if (isNegative != other.isNegative) {
        difference.digits = addDigits(digits, other.digits);
        difference.isNegative = isNegative;
    }
    else {
        auto result = subtractDigits(
            isNegative ? other.digits : digits,
            isNegative ? digits : other.digits);
        difference.isNegative = result.first;
        difference.digits = result.second;
    }

    difference.normalizeZero();
    return difference;
}

std::vector<char> BigInteger::addDigits(const std::vector<char>& lhs, const std::vector<char>& rhs) {

    const auto& smaller = (lhs.size() >  rhs.size()) ? rhs : lhs;
    const auto& greater = (lhs.size() <= rhs.size()) ? rhs : lhs;
    auto sum = greater;

    char carry = 0;
    for (std::size_t i = 0; i < smaller.size(); i++) {
        int digitSum = smaller[i] + sum[i] + carry;
        carry = static_cast<char>(digitSum / 10);
        sum[i] = digitSum % 10;
    }

    for (std::size_t i = smaller.size(); i < greater.size(); ++i) {
        int digitSum = sum[i] + carry;
        carry = static_cast<char>(digitSum / 10);
        sum[i] = digitSum % 10;
    }

    if (carry != 0) sum.push_back(carry);
    return sum;
}

std::pair<bool, std::vector<char>>
BigInteger::subtractDigits(const std::vector<char>& lhs, const std::vector<char>& rhs) {

    const auto& smaller = smallerSeq(lhs, rhs);
    const auto& greater = greaterSeq(lhs, rhs);
    std::vector<char> difference;

    char carry = 0;
    for (std::size_t i = 0; i < greater.size(); i++) {
        char left = greater[i];
        char right = carry + ((i >= smaller.size()) ? 0 : smaller[i]);
        if (left < right) {
            carry = 1;
            left += 10;
        }
        else carry = 0;
        difference.push_back(left - right);
    }

    removeLeadingZeroes(difference);
    return { &smaller == &lhs , difference };
}

// 3. Multiplication and division

template <typename T>
const BigInteger operator * (const T& value, const BigInteger& bigInteger) {
    return bigInteger * value;
}

const BigInteger BigInteger::operator * (const BigInteger& other) const {

    BigInteger product;
    std::size_t zeroes = std::abs(int(digits.size()) - int(other.digits.size()));
    if (zeroes != 0) {
        auto smaller = digits.size() > other.digits.size() ? other.digits : digits;
        const auto& greater = digits.size() > other.digits.size() ? digits : other.digits;
        addLeadingZeroes(smaller, zeroes);
        product.digits = multiplyDigits(greater, smaller);
    }
    else {
        product.digits = multiplyDigits(digits, other.digits);
    }

    product.isNegative = (isNegative != other.isNegative);
    removeLeadingZeroes(product.digits);
    product.normalizeZero();
    return product;
}

std::vector<char> BigInteger::multiplyDigits(const std::vector<char>& lhs, const std::vector<char>& rhs) {

    assert(lhs.size() == rhs.size());

    // base case, since lhs and rhs are always of the same size, we should encounter situations when only one of them
    // has size of 1 but not the other.
    if (lhs.size() == 1 && rhs.size() == 1) {
        int product = lhs[0] * rhs[0];
        std::vector<char> result { static_cast<char>(product % 10) };
        if (product >= 10) result.push_back(static_cast<char>(product / 10));
        return result;
    }

    std::size_t middle = lhs.size() / 2;

    std::vector<char> x0(lhs.begin(), std::next(lhs.begin(), middle));
    std::vector<char> x1(std::next(lhs.begin(), middle), lhs.end());

    std::vector<char> y0(rhs.begin(), std::next(rhs.begin(), middle));
    std::vector<char> y1(std::next(rhs.begin(), middle), rhs.end());

    auto z2 = multiplyDigits(x1, y1);
    auto z0 = multiplyDigits(x0, y0);

    auto z11 = addDigits(x1, x0);
    auto z12 = addDigits(y1, y0);
    auto z13 = multiplyDigits(z11, z12);

    // this subtraction should always result in positive number due to the nature of the algorithm.
    auto z1 = subtractDigits(z13, addDigits(z2, z0));
    assert(!z1.first);

    shiftUp(z2, 2 * middle);
    shiftUp(z1.second, middle);
    return addDigits(z2, addDigits(z1.second, z0));
}

#endif
