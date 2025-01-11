// https://atcoder.jp/contests/past19-open/tasks/past19_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    string S = "";
    bool left = false;
    int i = -1, x = 0;
    while (N--) {
        char c;
        cin >> c;
        if (!left) {
            if (c == '*' && !S.empty() && S.back() == '/' && x <= (int)S.size()-1) {
                left = true;
                i = S.size()-1;
            }
            S.push_back(c);
        } else {
            if (c == '/' && !S.empty() && S.back() == '*' && i+3 <= (int)S.size()) {
                while ((int)S.size() > i) {
                    S.pop_back();
                }
                left = false;
                x = i;
            } else {
                S.push_back(c);
            }
        }
    }
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
