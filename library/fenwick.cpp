#include "fenwick.h"
#include <vector>
#include <cassert>

struct Fenwick {
    Fenwick(int n)
    : sum(n + 1, 0)
    , length(n)
    {

    }

    void update(int k, int value) {
        assert(k >= 1 && k <= length);

        for(; k <= length; k += k & -k)
            sum[k] += value;
    }

    int query(int k) const {
        int answer {};

        assert(k <= length);

        for(; k > 0; k -= k & -k)
            answer += sum[k];

        return answer;
    }

private:
    std::vector<int> sum;
    int length;
};

extern "C" {

Fenwick* make_fenwick(int n) {
    return new Fenwick(n);
}

void update_fenwick(Fenwick* ft, int k, int value) {
    ft->update(k, value);
}

int query_fenwick(const Fenwick* ft, int k) {
    return ft->query(k);
}

void destroy_fenwick(Fenwick* ft) {
    delete ft;
}

}