#include "sum.h"
#include <emmintrin.h>
#include <stdalign.h>

float sum(float *vet, int n) {
    alignas(16) float res[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    for(int i = 0; i < n; i += 4)
        _mm_store_ps(res, _mm_add_ps(_mm_load_ps(res), _mm_loadu_ps(vet + i)));

    return res[0] + res[1] + res[2] + res[3];   
}