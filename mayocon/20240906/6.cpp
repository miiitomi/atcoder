// https://atcoder.jp/contests/abc286/tasks/abc286_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<ll> m{4, 9, 5, 7, 11, 13, 17, 19, 23};
    vector<ll> V;
    for (ll x : m) {
        ll s = V.size();
        for (ll k = 0; k < x; k++) {
            V.push_back(s+1+k);
        }
        V[(int)V.size()-1] = s;
    }
    ll M = V.size();
    cout << M << endl;
    for (int i = 0; i < M; i++) {
        cout << V[i]+1;
        if (i == M-1) cout << endl;
        else cout << " ";
    }

    vector<ll> W(M);
    for (int k = 0; k < M; k++) {
        cin >> W[k];
        W[k]--;
    }
    vector<ll> r(m.size());
    int idx = 0;
    for (int i = 0; i < (int)m.size(); i++) {
        r[i] = W[idx]-V[idx];
        idx += m[i];
    }

    auto ans = crt(r, m);
    cout << ans.first+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
