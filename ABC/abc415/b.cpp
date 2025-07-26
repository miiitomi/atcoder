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
    int tmp = -1;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] != '#') continue;
        if (tmp == -1) tmp = i;
        else {
            cout << tmp+1 << "," << i+1 << "\n";
            tmp = -1;
        }
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
