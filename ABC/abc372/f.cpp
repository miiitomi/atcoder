#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> X(M), Y(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    deque<mint> D(N, 0);
    D[0] = 1;
    vector<mint> tmp(M, 0);
    while (K--) {
        for (int j = 0; j < M; j++) {
            tmp[j] = D[X[j]];
        }
        D.push_front(D.back());
        D.pop_back();
        for (int j = 0; j < M; j++) {
            D[Y[j]] += tmp[j];
        }
    }
    mint ans = 0;
    for (mint x : D) ans += x;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
