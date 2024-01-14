// https://atcoder.jp/contests/abc157/tasks/abc157_e
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

int main() {
    ll N;
    cin >> N;
    vector<BIT> bit(26, BIT(N));
    string S;
    cin >> S;
    for (int i = 0; i < N; i++) {
        int k = S[i] - 'a';
        bit[k].add(i, 1);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            int x = S[i] - 'a';
            bit[x].add(i, -1);
            x = c - 'a';
            bit[x].add(i, 1);
            S[i] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                cnt += (bit[i].sum(l, r) > 0);
            }
            cout << cnt << "\n";
        }
    }
}
