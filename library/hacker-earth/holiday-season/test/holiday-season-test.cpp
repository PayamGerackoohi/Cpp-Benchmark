//
// Created by Payam Gerackoohi on 11.05.22.
//

#include "gtest/gtest.h"
#include "holiday-season.h"
#include "test-util.h"

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

TEST(HolidaySeasonTestSuite, Test) {
    assert_process(
            {
                    make_pair("5\n"
                              "ababa", "2\n"),
            }, [](istream &in, ostream &out) {
                process(in, out);
            }
    );
}

#pragma clang diagnostic pop
