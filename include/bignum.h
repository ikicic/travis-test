#ifndef BIGNUM_H
#define BIGNUM_H

#include <vector>
#include <string>
#include <cassert>


struct bignum {
    static constexpr int BASE = 1000;
    static constexpr int BASE_LOG = 3;
    static constexpr const char *FMT = "%03d";

    std::vector<int> v;

    bignum() {}
    bignum(const char *input);
    bignum(size_t size) : v(size) {}

    inline void resize(size_t size) {
        v.resize(size);
    }
    inline size_t size(void) const {
        return v.size();
    }
    inline bool empty(void) const {
        return v.empty();
    }
    inline int &operator[](size_t i) {
        assert(i < size());
        return v[i];
    }
    inline const int &operator[](size_t i) const {
        assert(i < size());
        return v[i];
    }
    inline int &back(void) {
        return v.back();
    }
    inline const int &back(void) const {
        return v.back();
    }
    inline void pop_back(void) {
        v.pop_back();
    }
};

bignum bn_add(const bignum &A, const bignum &B);
bignum bn_mult(const bignum &A, const bignum &B);
std::string bn_to_string(const bignum &A);
bignum bn_from_string(const char *A);
void bn_from_string(const char *A, bignum *target);

void _bn_trim_zeros(bignum *bn);

#endif
