//
// Created by Payam Gerackoohi on 4/3/2021 AD.
//

#include "big-integer.h"

using namespace std;

BigInteger::BigInteger(const string &number) {
    validate(number);
    adder = StringAdder();
    if (number.empty() || number == "0") {
        value = "0";
        sign = 0;
    } else if (number[0] == '-') {
        value = number.substr(1);
        if (value == "0")
            sign = 0;
        else
            sign = -1;
    } else if (number[0] == '+') {
        value = number.substr(1);
        if (value == "0")
            sign = 0;
        else
            sign = 1;
    } else {
        value = number;
        sign = 1;
    }
}

BigInteger::BigInteger(const BigInteger &other) {
    operator=(other);
}

BigInteger::BigInteger(BigInteger &&other) noexcept:
        adder(move(other.adder)),
        value(move(other.value)),
        sign(exchange(other.sign, 0)) {}

BigInteger &BigInteger::operator=(const BigInteger &other) {
    adder = StringAdder();
    value = other.value;
    sign = other.sign;
    return *this;
}

unique_ptr<string> BigInteger::size_ordered_add(const BigInteger &big, const BigInteger &small) {
    unique_ptr<string> result = nullptr;
    switch ((big.is_negative() << 1u) + small.is_negative()) {
        case 0: // ++
            result = adder.add(big.value, small.value, false);
            break;
        case 1: // +-
            result = adder.subtract(big.value, small.value, false);
            break;
        case 2: // -+
            result = adder.subtract(big.value, small.value, true);
            break;
        case 3: // --
            result = adder.add(big.value, small.value, true);
            break;
        default:
            throw;
    }
    return result;
}

unique_ptr<BigInteger> BigInteger::add(const BigInteger &other) {
    unique_ptr<string> result = nullptr;
    if (value > other.value)
        result = size_ordered_add(*this, other);
    else
        result = size_ordered_add(other, *this);
    return make_unique<BigInteger>(*result);
}

unique_ptr<BigInteger> BigInteger::subtract(const BigInteger &other) {
    auto copied = other;
    copied.negate();
    auto result = add(copied);
    return result;
}

string BigInteger::to_string() const {
    if (is_negative())
        return '-' + value;
    else
        return value;
}

void BigInteger::validate(const string &number) noexcept(false) {
    for (int i = 0; i < number.size(); ++i) {
        auto c = number[i];
        if (i == 0 && (c == '-' || c == '+'))
            continue;
        if (c < '0' || c > '9')
            throw std::out_of_range("");
    }
}
