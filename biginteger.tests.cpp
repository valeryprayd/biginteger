#include "gtest/gtest.h"
#include "biginteger.h"

// 1. Parsing

TEST(BigInteger, CorrectlyParsesNumberWithoutZeroes) {
    ASSERT_EQ(12345, BigInteger(12345));
}

TEST(BigInteger, CorrectlyParsesNumberWithZeroes) {
    ASSERT_EQ(12040, BigInteger(12040));
}

TEST(BigInteger, CorrectlyParsesNegativeNumberWithoutZeroes) {
    ASSERT_EQ(-12345, BigInteger(-12345));
}

TEST(BigInteger, CorrectlyParsesNegativeNumberWithZeroes) {
    ASSERT_EQ(-12040, BigInteger(-12040));
}

TEST(BigInteger, CorrectlyParsesZero) {
    ASSERT_EQ(0, BigInteger(0));
}

// 2.1 Addition for positives

TEST(BigInteger, CorrectlyAddsTwoPositiveNumbers1) {
    ASSERT_EQ(1333, BigInteger(34) + BigInteger(1299));
}

TEST(BigInteger, CorrectlyAddsTwoPositiveNumbers2) {
    ASSERT_EQ(1333, BigInteger(1299) + BigInteger(34));
}

TEST(BigInteger, CorrectlyAddsTwoPositiveNumbers3) {
    ASSERT_EQ(1000, BigInteger(999) + BigInteger(1));
}

TEST(BigInteger, CorrectlyAddsTwoPositiveNumbers4) {
    ASSERT_EQ(1000, BigInteger(1) + BigInteger(999));
}

TEST(BigInteger, CorrectlyAddsTwoMixedPositiveNumbers1) {
    ASSERT_EQ(1333, 34 + BigInteger(1299));
}

TEST(BigInteger, CorrectlyAddsTwoMixedPositiveNumbers2) {
    ASSERT_EQ(1333, BigInteger(1299) + 34);
}

TEST(BigInteger, CorrectlyAddsTwoMixedPositiveNumbers3) {
    ASSERT_EQ(1000, 999 + BigInteger(1));
}

TEST(BigInteger, CorrectlyAddsTwoMixedPositiveNumbers4) {
    ASSERT_EQ(1000, BigInteger(1) + 999);
}

// 2.2 Addition for positive and negative

TEST(BigInteger, CorrectlyAddsPositiveAndNegative1) {
    ASSERT_EQ(-7, BigInteger(-12) + BigInteger(5));
}

TEST(BigInteger, CorrectlyAddsPositiveAndNegative2) {
    ASSERT_EQ(-7, BigInteger(5) + BigInteger(-12));
}

TEST(BigInteger, CorrectlyAddsPositiveAndNegative3) {
    ASSERT_EQ(7, BigInteger(12) + BigInteger(-5));
}

TEST(BigInteger, CorrectlyAddsPositiveAndNegative4) {
    ASSERT_EQ(7, BigInteger(-5) + BigInteger(12));
}

TEST(BigInteger, CorrectlyAddsMixedPositiveAndNegative1) {
    ASSERT_EQ(-7, -12 + BigInteger(5));
}

TEST(BigInteger, CorrectlyAddsMixedPositiveAndNegative2) {
    ASSERT_EQ(-7, BigInteger(5) + (-12));
}

TEST(BigInteger, CorrectlyAddsMixedPositiveAndNegative3) {
    ASSERT_EQ(7, 12 + BigInteger(-5));
}

TEST(BigInteger, CorrectlyAddsMixedPositiveAndNegative4) {
    ASSERT_EQ(7, BigInteger(-5) + 12);
}

// 2.3 Addition for negatives

TEST(BigInteger, CorrectlyAddsTwoNegativeNumbers1) {
    ASSERT_EQ(-1333, BigInteger(-34) + BigInteger(-1299));
}

TEST(BigInteger, CorrectlyAddsTwoNegativeNumbers2) {
    ASSERT_EQ(-1333, BigInteger(-1299) + BigInteger(-34));
}

TEST(BigInteger, CorrectlyAddsTwoNegativeNumbers3) {
    ASSERT_EQ(-1000, BigInteger(-999) + BigInteger(-1));
}

TEST(BigInteger, CorrectlyAddsTwoNegativeNumbers4) {
    ASSERT_EQ(-1000, BigInteger(-1) + BigInteger(-999));
}

TEST(BigInteger, CorrectlyAddsTwoMixedNegativeNumbers1) {
    ASSERT_EQ(-1333, -34 + BigInteger(-1299));
}

TEST(BigInteger, CorrectlyAddsTwoMixedNegativeNumbers2) {
    ASSERT_EQ(-1333, BigInteger(-1299) + (-34));
}

TEST(BigInteger, CorrectlyAddsTwoMixedNegativeNumbers3) {
    ASSERT_EQ(-1000, -999 + BigInteger(-1));
}

TEST(BigInteger, CorrectlyAddsTwoMixedNegativeNumbers4) {
    ASSERT_EQ(-1000, BigInteger(-1) + (-999));
}

// 3.1 Subtraction for positives

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers1) {
    ASSERT_EQ(-1265, BigInteger(34) - BigInteger(1299));
}

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers2) {
    ASSERT_EQ(1265, BigInteger(1299) - BigInteger(34));
}

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers3) {
    ASSERT_EQ(-999, BigInteger(1) - BigInteger(1000));
}

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers4) {
    ASSERT_EQ(999, BigInteger(1000) - BigInteger(1));
}

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers5) {
    ASSERT_EQ(10, BigInteger(21) - BigInteger(11));
}

TEST(BigInteger, CorrectlySubtractsTwoPositiveNumbers6) {
    ASSERT_EQ(0, BigInteger(11) - BigInteger(11));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers1) {
    ASSERT_EQ(-1265, 34 - BigInteger(1299));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers2) {
    ASSERT_EQ(1265, BigInteger(1299) - 34);
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers3) {
    ASSERT_EQ(-999, 1 - BigInteger(1000));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers4) {
    ASSERT_EQ(999, BigInteger(1000) - 1);
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers5) {
    ASSERT_EQ(10, 21 - BigInteger(11));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedPositiveNumbers6) {
    ASSERT_EQ(0, BigInteger(11) - 11);
}

// 3.2 Subtraction for positive and negative

TEST(BigInteger, CorrectlySubtractsPositiveAndNegative1) {
    ASSERT_EQ(-17, BigInteger(-12) - BigInteger(5));
}

TEST(BigInteger, CorrectlySubtractsPositiveAndNegative2) {
    ASSERT_EQ(17, BigInteger(5) - BigInteger(-12));
}

TEST(BigInteger, CorrectlySubtractsPositiveAndNegative3) {
    ASSERT_EQ(17, BigInteger(12) - BigInteger(-5));
}

TEST(BigInteger, CorrectlySubtractsPositiveAndNegative4) {
    ASSERT_EQ(-17, BigInteger(-5) - BigInteger(12));
}

TEST(BigInteger, CorrectlySubtractsMixedPositiveAndNegative1) {
    ASSERT_EQ(-17, -12 - BigInteger(5));
}

TEST(BigInteger, CorrectlySubtractsMixedPositiveAndNegative2) {
    ASSERT_EQ(17, BigInteger(5) - (-12));
}

TEST(BigInteger, CorrectlySubtractsMixedPositiveAndNegative3) {
    ASSERT_EQ(17, 12 - BigInteger(-5));
}

TEST(BigInteger, CorrectlySubtractsMixedPositiveAndNegative4) {
    ASSERT_EQ(-17, BigInteger(-5) - 12);
}


// 3.3 Subtraction for negatives

TEST(BigInteger, CorrectlySubtractsTwoNegativeNumbers1) {
    ASSERT_EQ(1265, BigInteger(-34) - BigInteger(-1299));
}

TEST(BigInteger, CorrectlySubtractsTwoNegativeNumbers2) {
    ASSERT_EQ(-1265, BigInteger(-1299) - BigInteger(-34));
}

TEST(BigInteger, CorrectlySubtractsTwoNegativeNumbers3) {
    ASSERT_EQ(999, BigInteger(-1) - BigInteger(-1000));
}

TEST(BigInteger, CorrectlySubtractsTwoNegativeNumbers4) {
    ASSERT_EQ(-999, BigInteger(-1000) - BigInteger(-1));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedNegativeNumbers1) {
    ASSERT_EQ(1265, -34 - BigInteger(-1299));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedNegativeNumbers2) {
    ASSERT_EQ(-1265, BigInteger(-1299) - (-34));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedNegativeNumbers3) {
    ASSERT_EQ(999, -1 - BigInteger(-1000));
}

TEST(BigInteger, CorrectlySubtractsTwoMixedNegativeNumbers4) {
    ASSERT_EQ(-999, BigInteger(-1000) - (-1));
}

// 4. Multiplication for positives

TEST(BigInteger, CorrectlyMultipliesTwoPositiveNumbers1) {
    ASSERT_EQ(408, BigInteger(12) * BigInteger(34));
}

TEST(BigInteger, CorrectlyMultipliesTwoPositiveNumbers2) {
    ASSERT_EQ(56088, BigInteger(123) * BigInteger(456));
}

TEST(BigInteger, CorrectlyMultipliesTwoPositiveNumbers3) {
    ASSERT_EQ(5472, BigInteger(12) * BigInteger(456));
}

TEST(BigInteger, CorrectlyMultipliesTwoPositiveNumbers4) {
    ASSERT_EQ(148140, BigInteger(12) * BigInteger(12345));
}

TEST(BigInteger, CorrectlyMultipliesTwoPositiveNumbers5) {
    ASSERT_EQ(148140, BigInteger(12345) * BigInteger(12));
}

TEST(BigInteger, CorrectlyMultipliesTwoMixedPositiveNumbers1) {
    ASSERT_EQ(408, 12 * BigInteger(34));
}

TEST(BigInteger, CorrectlyMultipliesTwoMixedPositiveNumbers2) {
    ASSERT_EQ(56088, BigInteger(123) * 456);
}

TEST(BigInteger, CorrectlyMultipliesTwoMixedPositiveNumbers3) {
    ASSERT_EQ(5472, 12 * BigInteger(456));
}

TEST(BigInteger, CorrectlyMultipliesTwoMixedPositiveNumbers4) {
    ASSERT_EQ(148140, BigInteger(12) * 12345);
}

TEST(BigInteger, CorrectlyMultipliesTwoMixedPositiveNumbers5) {
    ASSERT_EQ(148140, 12345 * BigInteger(12));
}

// 4. Multiplication for positive and negative

TEST(BigInteger, CorrectlyMultipliesPositiveAndNegativeNumbers1) {
    ASSERT_EQ(-408, BigInteger(-12) * BigInteger(34));
}

TEST(BigInteger, CorrectlyMultipliesPositiveAndNegativeNumbers2) {
    ASSERT_EQ(-56088, BigInteger(123) * BigInteger(-456));
}

TEST(BigInteger, CorrectlyMultipliesPositiveAndNegativeNumbers3) {
    ASSERT_EQ(5472, BigInteger(-12) * BigInteger(-456));
}

TEST(BigInteger, CorrectlyMultipliesMixedPositiveAndNegativeNumbers1) {
    ASSERT_EQ(-408, -12 * BigInteger(34));
}

TEST(BigInteger, CorrectlyMultipliesMixedPositiveAndNegativeNumbers2) {
    ASSERT_EQ(-56088, BigInteger(-123) * 456);
}

TEST(BigInteger, CorrectlyMultipliesMixedPositiveAndNegativeNumbers3) {
    ASSERT_EQ(5472, -12 * BigInteger(-456));
}
