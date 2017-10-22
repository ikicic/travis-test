#ifndef _TEST_H_
#define _TEST_H_

void _check(const char *msg, const char *file, int line);

#define CHECK(x) (void)((x) || (_check(#x, __FILE__, __LINE__), 0))

#endif

