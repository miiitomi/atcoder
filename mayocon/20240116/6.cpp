// https://atcoder.jp/contests/abc285/tasks/abc285_f
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = 0;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return a + b;
    }

    // Update data[i] to a.
    void update(int i, T a) {
        i = n - 1 + i;
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        T vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        T vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<SegmentTree<int>> st(26, SegmentTree<int>(N));
    for (int i = 0; i < N; i++) {
        int j = S[i] - 'a';
        st[j].update(i, 1);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            st[(int)(S[i]-'a')].update(i, 0);
            st[(int)(c-'a')].update(i, 1);
            S[i] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            int ma = 100, mb = -1, tmp=l;
            vector<int> cnt(26, 0);
            for (int i = 0; i < 26; i++) {
                cnt[i] = st[i].query(l, r);
                if (cnt[i]) {
                    ma = min(ma, i);
                    mb = max(mb, i);
                }
            }
            bool ok = true;
            for (int i = ma+1; i < mb; i++) {
                if (st[i].query(0, l) || st[i].query(r, N)) {
                    ok = false;
                    goto HERE;
                }
            }
            for (int i = ma; i <= mb; i++) {
                if (cnt[i] != st[i].query(tmp, tmp+cnt[i])) {
                    ok = false;
                    goto HERE;
                }
                tmp += cnt[i];
            }
            HERE:
            if (ok) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
