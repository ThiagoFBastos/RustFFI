#ifndef FENWICK_H
#define FENWICK_H

struct Fenwick {
    int *sum;
    int n;
};

typedef struct Fenwick Fenwick;

Fenwick* make_fenwick(int n);
void update(Fenwick* ft, int k, int value);
int query(const Fenwick* ft, int k);
void delete_fenwick(Fenwick* ft);

#endif