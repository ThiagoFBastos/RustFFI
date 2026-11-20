#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Fenwick Fenwick;

Fenwick* make_fenwick(int n);
void update_fenwick(Fenwick* ft, int k, int value);
int query_fenwick(const Fenwick* ft, int k);
void destroy_fenwick(Fenwick* ft);

#ifdef __cplusplus
}
#endif