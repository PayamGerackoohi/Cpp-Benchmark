//
// Created by Payam Gerackoohi on 11.05.22.
//

#include <file-util.h>
#include <test-util.h>
#include "gtest/gtest.h"
#include "will-she-accept-him.h"

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

TEST(WillSheAcceptHimTestSuite, DummyTest) {
    auto input = read_file("Input.txt");
    auto output = read_file("Output.txt");
    assert_process({make_pair(*input, *output)}, [](istream &in, ostream &out) { process(in, out); });
}

#pragma clang diagnostic pop
