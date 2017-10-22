#include "bignum.h"
#include "test.h"

void test_to_string(void) {
    CHECK(bn_to_string(bignum()) == "0");

    constexpr int TESTS = 100;
    constexpr int MAX_DIGITS = 100;
    srand(1);

    char number[MAX_DIGITS + 1];
    for (int i = 0; i < TESTS; ++i) {
        int len = 1 + rand() % MAX_DIGITS;
        for (int j = 0; j < len; ++j)
            number[j] = '0' + rand() % 10;
        number[len] = 0;

        bignum A = bn_from_string(number);

        // Skip leading zeros.
        int k = 0;
        while (k < len && number[k] == '0')
            ++k;

        std::string str = bn_to_string(A);
        if (k == len) {
            CHECK(str == "0");
        } else {
            CHECK(str == std::string(number + k, number + len));
        }
    }
}
