#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    string T = S;
    for (int i = 0; i < (int)S.size(); i++) {
        if ((i == 0 || S[i-1] == '#') && S[i] == '.') {
            T[i] = 'o';
        }
    }
    cout << T << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
