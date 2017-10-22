#include "test.h"
#include <cstdio>
#include <cstdlib>

void _check(const char *msg, const char *file, int line) {
    fprintf(stderr, "Test failed: %s\n", msg);
    fprintf(stderr, "File: %s\n", file);
    fprintf(stderr, "Line: %d\n", line);
    fflush(stdout);
    fflush(stderr);
    abort();
}

