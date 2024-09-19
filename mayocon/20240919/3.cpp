// https://atcoder.jp/contests/abc173/tasks/abc173_d
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> v{0, A.back()};
    for (int i = N-2; i >= 0 && (int)v.size() < N; i--) {
        v.push_back(A[i]);
        v.push_back(A[i]);
    }
    while ((int)v.size() > N) v.pop_back();
    ll ans = 0;
    for (ll x : v) ans += x;
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
