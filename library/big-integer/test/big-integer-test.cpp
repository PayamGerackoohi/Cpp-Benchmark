//
// Created by Payam Gerackoohi on 11.05.22.
//

#include "big-integer.h"
#include "gtest/gtest.h"
#include <string>

#define TestSuite BigIntegerTestSuite

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp" // Clang-Tidy: Initialization of 'test_info_' with static storage duration may throw an exception that cannot be caught

TEST(TestSuite, NormalParseTest) {
    BigInteger a("");
    ASSERT_EQ(a.to_string(), "0");
    ASSERT_EQ(a.abs_string(), "0");
    ASSERT_EQ(a.signal(), 0);

    a = BigInteger("0");
    ASSERT_EQ(a.to_string(), "0");
    ASSERT_EQ(a.abs_string(), "0");
    ASSERT_EQ(a.signal(), 0);

    a = BigInteger("-0");
    ASSERT_EQ(a.to_string(), "0");
    ASSERT_EQ(a.abs_string(), "0");
    ASSERT_EQ(a.signal(), 0);

    a = BigInteger("+0");
    ASSERT_EQ(a.to_string(), "0");
    ASSERT_EQ(a.abs_string(), "0");
    ASSERT_EQ(a.signal(), 0);

    a = BigInteger("123");
    ASSERT_EQ(a.to_string(), "123");
    ASSERT_EQ(a.abs_string(), "123");
    ASSERT_EQ(a.signal(), 1);

    a = BigInteger("-123");
    ASSERT_EQ(a.to_string(), "-123");
    ASSERT_EQ(a.abs_string(), "123");
    ASSERT_EQ(a.signal(), -1);
}

TEST(TestSuite, ParseFailureTest) {
    ASSERT_ANY_THROW(BigInteger("?"));
    ASSERT_ANY_THROW(BigInteger("- 0"));
    ASSERT_ANY_THROW(BigInteger("   0"));
    ASSERT_ANY_THROW(BigInteger(" 0"));
    ASSERT_ANY_THROW(BigInteger("0 "));
    ASSERT_ANY_THROW(BigInteger("-1-"));
    ASSERT_ANY_THROW(BigInteger("-+1"));
    ASSERT_ANY_THROW(BigInteger("1.3"));
}

TEST(TestSuite, TrimAndReverseTest) {
    StringAdder adder;
    ASSERT_EQ(*adder.subtract("111123", "111000", false), "123");
    ASSERT_EQ(*adder.subtract("111123", "111000", true), "-123");
}

TEST(TestSuite, AdditionTest) {
    ASSERT_EQ((BigInteger("-1").add(BigInteger("10")))->to_string(), "9");
    ASSERT_EQ((BigInteger("-123456").add(BigInteger("123456")))->to_string(), "0");
    ASSERT_EQ((BigInteger("123456").add(BigInteger("-123456")))->to_string(), "0");
    ASSERT_EQ((BigInteger("-123456").add(BigInteger("123457")))->to_string(), "1");
    ASSERT_EQ((BigInteger("-123456").add(BigInteger("123455")))->to_string(), "-1");
    ASSERT_EQ((BigInteger("10").add(BigInteger("-1")))->to_string(), "9");
    ASSERT_EQ((BigInteger("1000").add(BigInteger("-1")))->to_string(), "999");
    ASSERT_EQ((BigInteger("1").add(BigInteger("-10")))->to_string(), "-9");
    ASSERT_EQ((BigInteger("-10").add(BigInteger("1")))->to_string(), "-9");
    ASSERT_EQ((BigInteger("-1000").add(BigInteger("1")))->to_string(), "-999");
    ASSERT_EQ((BigInteger("1").add(BigInteger("1")))->to_string(), "2");
    ASSERT_EQ((BigInteger("1").add(BigInteger("-1")))->to_string(), "0");
    ASSERT_EQ((BigInteger("-1").add(BigInteger("1")))->to_string(), "0");
    ASSERT_EQ((BigInteger("-1").add(BigInteger("-1")))->to_string(), "-2");
    ASSERT_EQ((BigInteger("1").add(BigInteger("10")))->to_string(), "11");
    ASSERT_EQ((BigInteger("10").add(BigInteger("1")))->to_string(), "11");
    ASSERT_EQ((BigInteger("1").add(BigInteger("999999999")))->to_string(), "1000000000");
    ASSERT_EQ((BigInteger("999999999").add(BigInteger("1")))->to_string(), "1000000000");
    ASSERT_EQ((BigInteger("123").add(BigInteger("123")))->to_string(), "246");

    BigInteger big1(
            "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    BigInteger big2(
            "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    auto expected = "24691357802469135780246913578024691357802469135780246913578024691357802469135780246913578024691357802469135780246913578024691357802469135780";
    ASSERT_EQ(big1.add(big2)->to_string(), expected);
    ASSERT_EQ(big1.subtract(big2)->to_string(), "0");
}

TEST(TestSuite, SubtractionTest) {
    ASSERT_EQ((BigInteger("-1").subtract(BigInteger("10")))->to_string(), "-11");
    ASSERT_EQ((BigInteger("-123456").subtract(BigInteger("123456")))->to_string(), "-246912");
    ASSERT_EQ((BigInteger("123456").subtract(BigInteger("-123456")))->to_string(), "246912");
    ASSERT_EQ((BigInteger("-123456").subtract(BigInteger("123457")))->to_string(), "-246913");
    ASSERT_EQ((BigInteger("-123456").subtract(BigInteger("123455")))->to_string(), "-246911");
    ASSERT_EQ((BigInteger("10").subtract(BigInteger("-1")))->to_string(), "11");
    ASSERT_EQ((BigInteger("1000").subtract(BigInteger("-1")))->to_string(), "1001");
    ASSERT_EQ((BigInteger("1").subtract(BigInteger("-10")))->to_string(), "11");
    ASSERT_EQ((BigInteger("-10").subtract(BigInteger("1")))->to_string(), "-11");
    ASSERT_EQ((BigInteger("-1000").subtract(BigInteger("1")))->to_string(), "-1001");
    ASSERT_EQ((BigInteger("1").subtract(BigInteger("1")))->to_string(), "0");
    ASSERT_EQ((BigInteger("1").subtract(BigInteger("-1")))->to_string(), "2");
    ASSERT_EQ((BigInteger("-1").subtract(BigInteger("1")))->to_string(), "-2");
    ASSERT_EQ((BigInteger("-1").subtract(BigInteger("-1")))->to_string(), "0");
    ASSERT_EQ((BigInteger("1").subtract(BigInteger("10")))->to_string(), "-9");
    ASSERT_EQ((BigInteger("10").subtract(BigInteger("1")))->to_string(), "9");
    ASSERT_EQ((BigInteger("1").subtract(BigInteger("999999999")))->to_string(), "-999999998");
    ASSERT_EQ((BigInteger("999999999").subtract(BigInteger("1")))->to_string(), "999999998");
    ASSERT_EQ((BigInteger("123").subtract(BigInteger("123")))->to_string(), "0");

    BigInteger big1(
            "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    BigInteger big2(
            "-12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    auto expected = "24691357802469135780246913578024691357802469135780246913578024691357802469135780246913578024691357802469135780246913578024691357802469135780";
    ASSERT_EQ(big1.subtract(big2)->to_string(), expected);
    ASSERT_EQ(big1.add(big2)->to_string(), "0");
}

/**
 * BigInteger::add(const BigInteger &) relies on numerical string comparison
 */
TEST(TestSuite, StringComparisonTest) {
    ASSERT_EQ(string("123") > string("12"), true);
    ASSERT_EQ(string("123") > string("122"), true);
    ASSERT_EQ(string("123") == string("123"), true);
    ASSERT_EQ(string("123") < string("124"), true);
    ASSERT_EQ(string("123") < string("1245"), true);
}

/**
 * BigInteger::size_ordered_add(const BigInteger &, const BigInteger &) relies on bool to int conversion
 */
TEST(TestSuite, BoolToIntConversionTest) {
    ASSERT_EQ(true, 1);
    ASSERT_EQ(false, 0);
}

#pragma clang diagnostic pop
