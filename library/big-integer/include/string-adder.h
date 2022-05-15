//
// Created by Payam Gerackoohi on 14.05.22.
//

#ifndef BENCHMARK_STRING_ADDER_H
#define BENCHMARK_STRING_ADDER_H

#include <sstream>

class StringAdder {
    enum class Operation {
        Addition, Subtraction
    };

    std::stringstream ss;
    char result = '0';
    int8_t carry = 0;
    bool is_negative = false;
    Operation operation = Operation::Addition;

    void calculate_carry();

    std::unique_ptr<std::string> trim_and_reverse();

    void reset();

    std::unique_ptr<std::string> add_subtract(const std::string &, const std::string &, bool negative);

    void operate(const char &&);

public:
    StringAdder() = default;

    StringAdder(const StringAdder &);

    StringAdder(StringAdder &&) noexcept;

    StringAdder &operator=(const StringAdder &);

    std::unique_ptr<std::string> add(const std::string &big, const std::string &small, bool negative);

    std::unique_ptr<std::string> subtract(const std::string &big, const std::string &small, bool negative);
};

#endif //BENCHMARK_STRING_ADDER_H
