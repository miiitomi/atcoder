#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<vector<ll>> B(M+1);
    ll ans = 0;
    fenwick_tree<ll> f(M);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        ans += f.sum(a+1, M);
        f.add(a, 1);
        B[M-a].push_back(i);
    }
    cout << ans << "\n";
    for (int k = 1; k <= M-1; k++) {
        for (int i : B[k]) {
            ans += i - (N-i-1);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
