#include "bignum.h"
#include <cstdio>
#include <cstring>

void _bn_trim_zeros(bignum *A) {
    while (!A->empty() && A->back() == 0)
        A->pop_back();
}

bignum bn_from_string(const char *input) {
    bignum result;
    bn_from_string(input, &result);
    return result;
}

void bn_from_string(const char *input, bignum *out) {
    constexpr int DIGITS = bignum::BASE_LOG;
    int len = strlen(input);
    out->resize((len + DIGITS - 1) / DIGITS);
    for (int i = 0; i < (int)out->size(); ++i)
        (*out)[i] = 0;

    int pot10 = 1;
    int digit = 0;
    int pos = 0;
    for (int i = len - 1; i >= 0; --i) {
        (*out)[pos] += pot10 * (input[i] - '0');
        if (digit < DIGITS - 1) {
            ++digit;
            pot10 *= 10;
        } else {
            digit = 0;
            pot10 = 1;
            ++pos;
        }
    }
    _bn_trim_zeros(out);
}

std::string bn_to_string(const bignum &A) {
    constexpr int DIGITS = bignum::BASE_LOG;
    if (A.empty())
        return "0";
    std::string result;
    result.reserve(A.size() * DIGITS);

    char tmp[DIGITS + 1];
    for (int i = (int)A.size() - 1; i >= 0; --i) {
        sprintf(tmp, i < (int)A.size() - 1 ? bignum::FMT : "%d", A[i]);
        result += tmp;
    }
    return result;
}
