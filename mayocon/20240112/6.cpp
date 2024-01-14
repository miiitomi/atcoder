// https://atcoder.jp/contests/abc206/tasks/abc206_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int L, R;
    cin >> L >> R;
    vector<ll> cnt(R+1, 0);
    ll ans = 0;
    for (ll x = R; x >= 2; x--) {
        ll k = 0;
        for (ll y = 2*x; y <= R; y += x) {
            cnt[x] -= cnt[y];
            if (L <= y) k++;
        }
        ans += k * (k-1) + cnt[x];
        if (L <= x) k++;
        cnt[x] += k * (k-1);
    }
    cout << ans << endl;
}
