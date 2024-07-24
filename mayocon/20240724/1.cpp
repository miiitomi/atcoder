// https://atcoder.jp/contests/abc117/tasks/abc117_b
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
    vector<ll> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());
    ll sum = 0;
    for (ll i = 0; i < N-1; i++) sum += L[i];
    if (sum > L.back()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
