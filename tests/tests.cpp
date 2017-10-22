#include "test.h"
#include <cstdio>
#include <cstdlib>

void test_from_string(void);
void test_to_string(void);
void test_mult(void);

void run_all_tests(void) {
    test_from_string();
    test_to_string();
    test_mult();
}

int main(void) {
    run_all_tests();
    printf("TESTS OK\n");
    return 0;
}
