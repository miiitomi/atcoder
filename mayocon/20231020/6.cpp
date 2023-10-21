// https://atcoder.jp/contests/abc216/tasks/abc216_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> data;

    BIT(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, ll x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    ll sum(int i) {
        // compute sum of a[i] with i in [0, i)
        ll ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    ll sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

struct C {
    int l;
    int r;
    int x;

    C(int l, int r, int x): l(l), r(r), x(x) {};
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<C> Cs;
    Cs.reserve(M);
    for (int i = 0; i < M; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        Cs.push_back(C(l, r, x));
    }

    sort(Cs.begin(), Cs.end(), [](C &a, C&b){if (a.r != b.r) return a.r < b.r; else return a.l < b.l;});
    vector<int> A(N, 0);
    vector<int> R;
    int nr = 0;
    BIT bit(N);

    for (C &c: Cs) {
        while (nr <= c.r) {
            R.push_back(nr);
            nr++;
        }
        c.x -= bit.sum(c.l, c.r+1);
        while (c.x > 0) {
            c.x--;
            int v = R.back();
            R.pop_back();
            A[v] = 1;
            bit.add(v, 1);
        }
    }

    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
}
