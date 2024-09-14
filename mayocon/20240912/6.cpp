// https://atcoder.jp/contests/abc359/tasks/abc359_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, ans = 0;
    cin >> N;
    vector<ll> A(N), d(N, 1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans += A[i];
        Q.push({3*A[i], i});
    }
    ll R = 2*(N-1) - N;
    while (R--) {
        auto [w, i] = Q.top();
        Q.pop();
        ans += w;
        d[i]++;
        Q.push({((d[i]+1)*(d[i]+1)-d[i]*d[i])*A[i], i});
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
