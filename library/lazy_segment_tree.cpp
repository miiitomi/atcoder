// https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LazySegmentTree {
    int n;
    vector<ll> data, lazy;

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, 0);
        lazy.assign(2*n-1, 0);
    }

    // 遅延評価
    void eval(int k, int l, int r) {
        if (lazy[k] == 0) return;  // 更新するものがないので終了
        if (k < n - 1) {
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        data[k] += (r - l) * lazy[k];
        lazy[k] = 0;
    }

    // [a, b) に x を加算.
    void _add(int a, int b, ll x, int k, int l, int r) {
        eval(k, l, r);
        if (a <= l && r <= b) {  // 完全に内側の場合
            lazy[k] = x;
            eval(k, l, r);
        } else if (a < r && l < b) {  // 領域が一部重なる場合
            _add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            _add(a, b, x, k * 2 + 2, (l + r) / 2, r);
            data[k] = data[k * 2 + 1] + data[k * 2 + 2];
        }
    }

    // [a, b) に x を加算.
    void add(int a, int b, ll x) {
        _add(a, b, x, 0, 0, n);
    }

    // [a, b) の和を計算.
    ll _sum(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) {  // 完全に外側の場合
            return 0;
        } else if (a <= l && r <= b) {  // 完全に内側の場合
            return data[k];
        } else {  // 一部重なる場合
            ll vl = _sum(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = _sum(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }

    // [a, b) の和を計算.
    ll sum(int a, int b) {
        return _sum(a, b, 0, 0, n);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    LazySegmentTree lst(N);
    for (int q = 0; q < Q; q++) {
        int c, s, t, x;
        cin >> c >> s >> t;
        s--;
        t--;
        if (c == 0) {
            cin >> x;
            lst.add(s, t+1, x);
        } else {
            cout << lst.sum(s, t+1) << endl;
        }
    }
}