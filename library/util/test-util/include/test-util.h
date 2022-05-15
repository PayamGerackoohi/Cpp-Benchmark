//
// Created by Payam Gerackoohi on 12.05.22.
//

#ifndef BENCHMARK_UTIL_H
#define BENCHMARK_UTIL_H

#include <iostream>

using test_input = std::initializer_list<std::pair<std::string, std::string>>;

using test_process = void(std::istream &cin, std::ostream &cout);

void assert_process(test_input &&given, test_process *process);

#endif //BENCHMARK_UTIL_H
