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
    int w = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == 'W') {
            w++;
        } else if (S[i] == 'A' && w > 0) {
            for (int j = 0; j < w; j++) S[i-j] = 'C';
            S[i-w] = 'A';
            w = 0;
        } else {
            w = 0;
        }
    }
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
