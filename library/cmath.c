#include "cmath.h"
#include <emmintrin.h>
#include <immintrin.h>
#include <stdalign.h>

float sum_float(float const * const vet, int n) {
    alignas(16) float res[4] = {0.0f};

    for(int i = 0; i < n; i += 4)
        _mm_store_ps(res, _mm_add_ps(_mm_load_ps(res), _mm_loadu_ps(vet + i)));

    return res[0] + res[1] + res[2] + res[3];
}

int sum_int(int const * const vet, int n) {
    alignas(16) int res[4] = {0};

    for(int i = 0; i < n; i += 4)
        _mm_store_si128((__m128i*)res, _mm_add_epi32(_mm_load_si128((const __m128i*)res), _mm_loadu_si128((const __m128i*)(vet + i))));

    return res[0] + res[1] + res[2] + res[3];
}

int xor(int const * const vet, int n) {
    alignas(16) int res[4] = {0};

    for(int i = 0; i < n; i += 4)
        _mm_store_si128((__m128i*)res, _mm_xor_si128(_mm_load_si128((const __m128i*)res), _mm_loadu_si128((const __m128i*)(vet + i))));

    return res[0] ^ res[1] ^ res[2] ^ res[3];
}