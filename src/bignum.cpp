#include "bignum.h"

bignum::bignum(const char *input) {
    bn_from_string(input, this);
}
