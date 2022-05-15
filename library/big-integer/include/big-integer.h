//
// Created by Payam Gerackoohi on 4/3/2021 AD.
//

#ifndef BENCHMARK_BIG_INTEGER_H
#define BENCHMARK_BIG_INTEGER_H

#include <string>
#include "string-adder.h"

class BigInteger {
    std::string value; // absolute value
    int8_t sign = 0; // -1, 0, 1
    StringAdder adder;

    static void validate(const std::string &number) noexcept(false);

    std::unique_ptr<std::string> size_ordered_add(const BigInteger &big, const BigInteger &small);

public:
    explicit BigInteger(const std::string &);

    BigInteger(const BigInteger &);

    BigInteger(BigInteger &&) noexcept;

    BigInteger &operator=(const BigInteger &);

    std::unique_ptr<BigInteger> add(const BigInteger &);

    std::unique_ptr<BigInteger> subtract(const BigInteger &);

    std::string to_string() const;

    inline std::string abs_string() const { return value; }

    inline int8_t signal() const { return sign; }

    inline bool is_negative() const { return sign < 0; }

    void negate() { sign = -sign; }
};

#endif //BENCHMARK_BIG_INTEGER_H
