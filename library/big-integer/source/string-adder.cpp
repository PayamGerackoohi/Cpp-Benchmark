//
// Created by Payam Gerackoohi on 14.05.22.
//

#include "string-adder.h"

using namespace std;

[[maybe_unused]]
StringAdder::StringAdder(const StringAdder &other) {
    operator=(other);
}

StringAdder::StringAdder(StringAdder &&other) noexcept:
        result(exchange(other.result, '0')),
        carry(exchange(other.carry, 0)),
        is_negative(exchange(other.is_negative, false)),
        operation(exchange(other.operation, Operation::Addition)) {}

StringAdder &StringAdder::operator=(const StringAdder &other) {
    result = other.result;
    carry = other.carry;
    is_negative = other.is_negative;
    operation = other.operation;
    return *this;
}

void StringAdder::calculate_carry() {
    if (result < '0') {
        result += 10;
        carry = -1;
    } else if (result > '9') {
        result -= 10;
        carry = 1;
    } else
        carry = 0;
    ss << result;
}

unique_ptr<string> StringAdder::trim_and_reverse() {
    auto str = ss.str();
    ss.str("");
    bool has_digit = false;
    for (auto i = str.size() - 1; /* size_t can underflow */ ; i--) {
        if (str[i] != '0')
            has_digit = true;
        if (has_digit)
            ss << str[i];
        if (i == 0)
            break;
    }
    auto res = ss.str();
    if (res.empty())
        res = "0";
    else if (is_negative)
        res = '-' + res;
    return make_unique<string>(res);
}

inline void StringAdder::operate(const char &&rhs) {
    if (operation == Operation::Addition)
        result = static_cast<char>(result + rhs);
    else
        result = static_cast<char>(result - rhs);
}

unique_ptr<string> StringAdder::add_subtract(const std::string &big, const std::string &small, bool negative) {
    reset();
    is_negative = negative;
    auto big_index = big.size() - 1;
    auto small_index = small.size() - 1;
    while (true) {
        result = static_cast<char>(big[big_index] + carry);
        operate(static_cast<char>(small[small_index] - '0'));
        calculate_carry();
        if (small_index == 0) {
            if (big_index != 0) {
                big_index--;
                while (true) {
                    result = static_cast<char>(big[big_index] + carry);
                    calculate_carry();
                    if (big_index == 0)
                        break;
                    big_index--;
                }
            }
            break;
        }
        small_index--;
        big_index--;
    }
    if (operation == Operation::Addition && carry == 1)
        ss << '1';
    return trim_and_reverse();
}

unique_ptr<string> StringAdder::add(const string &big, const string &small, bool negative) {
    operation = Operation::Addition;
    return add_subtract(big, small, negative);
}

unique_ptr<string> StringAdder::subtract(const string &big, const string &small, bool negative) {
    operation = Operation::Subtraction;
    return add_subtract(big, small, negative);
}

void StringAdder::reset() {
    ss.str("");
    carry = 0;
}
