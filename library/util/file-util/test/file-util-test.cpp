//
// Created by Payam Gerackoohi on 14.05.22.
//

#include "file-util.h"
#include <gtest/gtest.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

TEST(FileUtilTestSuite, Test) {
    auto input = read_file("Input.txt");
    ASSERT_EQ(*input, "a\nb");
    auto output = read_file("Output.txt");
    ASSERT_EQ(*output, "c\nd");
}

#pragma clang diagnostic pop
