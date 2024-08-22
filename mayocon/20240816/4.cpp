// https://atcoder.jp/contests/abc206/tasks/abc206_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    vector<vector<ll>> V(N);
    vector<ll> W(N);
    for (int i = 0; i < N; i++) {
        V[i].push_back(i);
        W[i] = i;
    }

    ll ans = 0;
    for (ll i = 0; i < N/2; i++) {
        ll l = W[A[i]], r = W[A[(int)A.size()-1-i]];
        if (l == r) continue;
        ans++;
        if (V[l].size() > V[r].size()) swap(l, r);
        while (!V[l].empty()) {
            ll x = V[l].back();
            V[l].pop_back();
            W[x] = r;
            V[r].push_back(x);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
