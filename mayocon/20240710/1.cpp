// https://atcoder.jp/contests/abc280/tasks/abc280_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<ll> S(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        cout << S[i+1]-S[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
