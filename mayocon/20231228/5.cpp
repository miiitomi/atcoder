// https://atcoder.jp/contests/abc174/tasks/abc174_f
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

struct Query {
    int i, l, r;
    Query (int i, int l, int r): i(i), l(l), r(r) {;}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> c(N);
    vector<deque<int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        c[i]--;
        v[c[i]].push_back(i);
    }

    BIT bit(N);
    for (int i = 0; i < N; i++) {
        if (!v[i].empty()) {
            int f = v[i].front();
            v[i].pop_front();
            bit.add(f, 1);
        }
    }

    vector<Query> Qs;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        Qs.push_back(Query(i, l-1, r-1));
    }
    sort(Qs.begin(), Qs.end(), [](const Query &a, const Query &b) {if (a.l != b.l) return a.l < b.l; else return a.r < b.r;});
    vector<int> ans(Q, -1);

    int tmp = 0;
    for (auto &q : Qs) {
        while (tmp < q.l) {
            int x = c[tmp];
            bit.add(tmp, -1);
            if (!v[x].empty()) {
                int y = v[x].front();
                v[x].pop_front();
                bit.add(y, 1);
            }
            tmp++;
        }
        ans[q.i] = bit.sum(q.l, q.r+1);
    }

    for (int a : ans) cout << a << "\n";
}
