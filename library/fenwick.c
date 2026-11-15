#include "fenwick.h"
#include <string.h>
#include <stdlib.h>

Fenwick* make_fenwick(int n) {
    Fenwick *ft = (Fenwick*)malloc(sizeof(Fenwick));
    ft->sum = (int*)malloc(sizeof(int) * (n + 1));
    ft->n = n;
    memset(ft->sum, 0, sizeof(int) * (n + 1));
    return ft;
}

void update(Fenwick* ft, int k, int value) {
    for(; k <= ft->n; k += k & -k)
        ft->sum[k] += value;
}

int query(const Fenwick* ft, int k) {
    int answer = 0;

    for(; k > 0; k -= k & -k)
        answer += ft->sum[k];

    return answer;
}

void delete_fenwick(Fenwick* ft) {
    free(ft);
}