#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M, L, S;
vector<ll> A;
map<pair<int, int>, bool> dp;
bool f(int X, int Y) {
    if (dp.count({X, Y})) return dp[{X, Y}];
    for (int i = 0; i < S; i++) {
        if (!(X & (1 << i))) continue;
        if (!f(Y, X ^ (1 << i))) return dp[{X, Y}] = true;
        for (int j = 0; j < S; j++) {
            if (!(X & (1 << j)) && !(Y & (1 << j)) && A[j] < A[i]) {
                if (!f(Y, (X ^ (1 << i))^(1 << j))) return dp[{X, Y}] = true;
            }
        }
    }
    return dp[{X, Y}] = false;
}

void solve() {
    cin >> N >> M >> L;
    S = N + M + L;
    A.resize(S);
    int X = 0, Y = 0;
    for (int i = 0; i < S; i++) {
        cin >> A[i];
        if (i < N) X ^= (1 << i);
        else if (i < N+M) Y ^= (1 << i);
    }
    if (f(X, Y)) cout << "Takahashi\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
