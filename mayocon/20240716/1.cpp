// https://atcoder.jp/contests/abc265/tasks/abc265_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(N+1, 0);
    for (int i = 1; i <= N-1; i++) cin >> A[i];
    vector<ll> Y(N+1, 0);
    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        Y[x] += y;
    }

    ll tmp = 1;
    while (tmp < N) {
        T += Y[tmp];
        if (T <= A[tmp]) break;
        T -= A[tmp];
        tmp++;
    }
    if (tmp == N) cout << "Yes\n";
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
