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
    for (int i = 1; i < (int)S.size(); i++) {
        char c = S[i];
        if ('a' <= c && c <= 'z') continue;
        c = S[i-1];
        bool ok = false;
        for (char d: T) {
            if (d == c) ok = true;
        }
        if (!ok) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
