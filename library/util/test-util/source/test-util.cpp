//
// Created by Payam Gerackoohi on 12.05.22.
//

#include "test-util.h"
#include <sstream>
#include "gtest/gtest.h"

using namespace std;

void assert_process(test_input &&given, test_process *p) {
    for (auto &item: given) {
        stringstream in;
        stringstream out;
        in << item.first;
        p(in, out);
        string result = out.str();
        string expected = item.second;
        ASSERT_EQ(expected, result);
    }
}
