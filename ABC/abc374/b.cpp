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
    string T;
    cin >> S;
    cin >> T;
    if (S == T) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < min((int)S.size(), (int)T.size()); i++) {
        if (S[i] != T[i]) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << min((int)S.size(), (int)T.size())+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
