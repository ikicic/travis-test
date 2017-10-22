#include "bignum.h"
#include "test.h"

void test_mult(void) {
    {
        bignum A = bn_from_string("43852903859028508239045820345");
        bignum B = bn_from_string("237489523545");
        bignum C = bn_mult(A, B);
        CHECK(bn_to_string(C) == "10414605243545372268263098839157717523025");
    }
    {
        bignum A = bn_from_string("43852903859028508239045820345");
        bignum B = bn_from_string("0");
        bignum C = bn_mult(A, B);
        CHECK(bn_to_string(C) == "0");
    }
}
