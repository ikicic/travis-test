#include "bignum.h"
#include "test.h"

void test_from_string(void) {
    {
        bignum A("");
        CHECK(A.size() == 0);
    }
    {
        bignum A("0");
        CHECK(A.size() == 0);
    }
    {
        bignum A("1");
        CHECK(A.size() == 1 && A[0] == 1);
    }
    {
        bignum A("12");
        CHECK(A.size() == 1 && A[0] == 12);
    }
    {
        bignum A("123");
        CHECK(A.size() == 1 && A[0] == 123);
    }
    {
        bignum A("023");
        CHECK(A.size() == 1 && A[0] == 23);
    }
    {
        bignum A("0123");
        CHECK(A.size() == 1 && A[0] == 123);
    }
    {
        bignum A("0000001234567");
        CHECK(A.size() == 3 && A[0] == 567 && A[1] == 234 && A[2] == 1);
    }
    {
        bignum A("1234");
        CHECK(A.size() == 2 && A[0] == 234 && A[1] == 1);
    }
    {
        bignum A("12345");
        CHECK(A.size() == 2 && A[0] == 345 && A[1] == 12);
    }
    {
        bignum A("123456");
        CHECK(A.size() == 2 && A[0] == 456 && A[1] == 123);
    }
    {
        bignum A("0123456");
        CHECK(A.size() == 2 && A[0] == 456 && A[1] == 123);
    }
    {
        bignum A("93802483");
        CHECK(A.size() == 3 && A[0] == 483 && A[1] == 802 && A[2] == 93);
    }
}

