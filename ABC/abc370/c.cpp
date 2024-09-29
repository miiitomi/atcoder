#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S, T;
    cin >> S >> T;
    vector<string> X;
    int N = S.size();
    while (S != T) {
        string U = string(N, 'z');
        for (int i = 0; i < N; i++) {
            if (S[i] == T[i]) continue;
            string N = S;
            N[i] = T[i];
            if (N < U) swap(N, U);
        }
        X.push_back(U);
        swap(S, U);
    }
    cout << X.size() << "\n";
    for (string s : X) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
