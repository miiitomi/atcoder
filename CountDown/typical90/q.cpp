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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> L(M);
    vector<ll> cnt(N, 0);

    for (int i = 0; i < M; i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        L[i] = make_pair(l, r);
        cnt[l]++;
        cnt[r]++;
    }

    ll ans = M * (M-1) / 2LL;

    for (int x = 0; x < N; x++) {
        ans -= cnt[x]*(cnt[x]-1)/2;
    }

    sort(L.begin(), L.end());
    BIT bit1(N);
    for (auto p : L) {
        ans -= bit1.sum(0, p.first);
        bit1.add(p.second, 1);
    }

    sort(L.begin(), L.end(), [](pair<ll,ll> &a, pair<ll,ll> &b){if (a.second != b.second) return a.second < b.second; else return a.first < b.first;});
    BIT bit2(N);
    for (auto p : L) {
        ans -= bit2.sum(p.first+1, p.second);
        bit2.add(p.first, 1);
    }

    cout << ans << endl;
}
