//
// Created by Payam Gerackoohi on 11.05.22.
//

#include "gtest/gtest.h"
#include "async.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

TEST(AsyncTestSuite, DummyTest) {
    async_sample();
    ASSERT_EQ(1, 1);
}

#pragma clang diagnostic pop
