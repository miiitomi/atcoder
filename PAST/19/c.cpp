// https://atcoder.jp/contests/past19-open/tasks/past19_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_good(string S) {
    for (int i = 0; i < (int)S.size()-1; i++) {
        if (abs((int)S[i]-(int)S[i+1]) > 1) return false;
    }
    return true;
}

void solve() {
    string N;
    cin >> N;
    ll K = N.size();
    for (int i = 0; i < K; i++) {
        for (char c = '0'; c <= '9'; c++) {
            if (i == 0 && c == '0') continue;
            string S = N;
            S[i] = c;
            if (is_good(S)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
