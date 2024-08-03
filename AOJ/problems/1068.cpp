#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;

template <typename T> struct SegmentTree2D {
    int H, W;
    vector<T> data;
    T identity = INF;  // TODO: Set identity value.
    T op(T l, T r) {return min(l, r);}  // TODO: Set op function.

    SegmentTree2D(int h, int w) {
        H = 1; W = 1;
        while (H < h) H *= 2;
        while (W < w) W *= 2;
        data.assign(4*H*W, identity);
    }

    int id(int h, int w) {return h*2*W + w;}

    void initialize(int h, int w, T x) {
        // REMARK: Only use it before build().
        data[id(h+H, w+W)] = x;
    }

    void build() {
        // REMARK: Run build() after initialize().
        for (int w = W; w < 2*W; w++) {
            for (int h = H-1; h > 0; h--) {
                data[id(h, w)] = op(data[id(2*h, w)], data[id(2*h+1, w)]);
            }
        }
        for (int h = 0; h < 2*H; h++) {
            for (int w = W-1; w > 0; w--) {
                data[id(h, w)] = op(data[id(h, 2*w)], data[id(h, 2*w+1)]);
            }
        }
    }

    void update(int h, int w, T x) {
        h += H; w += W;
        data[id(h, w)] = x;
        for (int i = (h >> 1); i > 0; i >>= 1) {
            data[id(i,w)] = op(data[id(2*i, w)], data[id(2*i+1, w)]);
        }
        for (; h > 0; h >>= 1) {
            for (int j = (w >> 1); j > 0; j >>= 1) {
                data[id(h,j)] = op(data[id(h, 2*j)], data[id(h, 2*j+1)]);
            }
        }
    }

    T _sub_query(int h, int w1, int w2) {
        T res = identity;
        for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
            if (w1 & 1) {
                res = op(res, data[id(h, w1)]);
                w1++;
            }
            if (w2 & 1) {
                w2--;
                res = op(res, data[id(h, w2)]);
            }
        }
        return res;
    }

    T query(int h1, int w1, int h2, int w2) {
        // Return the answer to the query of [h1, h2) * [w1, w2)
        if (h1 >= h2 || w1 >= w2) return identity;
        T res = identity;
        h1 += H; h2 += H; w1 += W; w2 += W;
        for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
            if (h1 & 1) {
                res = op(res, _sub_query(h1, w1, w2));
                h1++;
            }
            if (h2 & 1) {
                h2--;
                res = op(res, _sub_query(h2, w1, w2));
            }
        }
        return res;
    }

    T get(int h, int w) {
        // Get the value at the point (h, w).
        return data[id(h+H, w+W)];
    }
};

bool solve() {
    ll R, C, Q;
    cin >> R >> C >> Q;
    if (R == 0 && C == 0 && Q == 0) return true;

    SegmentTree2D<ll> st(R, C);
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            ll x;
            cin >> x;
            st.update(r, c, x);
        }
    }

    while (Q--) {
        ll r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r2++; c2++;
        cout << st.query(r1, c1, r2, c2) << "\n";
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    bool done = false;
    while (!done) done = solve();
}
