// https://atcoder.jp/contests/abc202/tasks/abc202_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<vector<ll>> C(61, vector<ll>(61));

void f(ll A, ll B, ll K, string &S) {
    if (A == 0) {
        while (B--) S.push_back('b');
        return;
    }
    if (B == 0) {
        while (A--) S.push_back('a');
        return;
    }

    ll left = C[A+B-1][A-1];
    if (left >= K) {
        S.push_back('a');
        f(A-1, B, K, S);
    } else {
        K -= left;
        S.push_back('b');
        f(A, B-1, K, S);
    }
}

void solve() {
    ll A, B, K;
    cin >> A >> B >> K;
    string S = "";
    f(A, B, K, S);
    cout << S << "\n";
}

int main() {
    for (int n = 0; n <= 60; n++) {
        for (int k = 0; k <= 60; k++) {
            if (k == 0 || k == n) C[n][k] = 1;
            else if (k > n) C[n][k] = 0;
            else C[n][k] = C[n-1][k-1] + C[n-1][k];
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
