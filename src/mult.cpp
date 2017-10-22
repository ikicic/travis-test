#include "bignum.h"
#include <cassert>

bignum bn_mult(const bignum &A, const bignum &B) {
    bignum C(A.size() + B.size());

    for (size_t i = 0; i < A.size(); ++i)
        for (size_t j = 0; j < B.size(); ++j)
            C[i + j] += A[i] * B[j];

    int carry = 0;
    for (size_t i = 0; i < C.size(); ++i) {
        int curr = C[i] + carry;
        C[i] = curr % bignum::BASE;
        carry = curr / bignum::BASE;
    }
    assert(carry == 0);
    _bn_trim_zeros(&C);
    return C;
}
