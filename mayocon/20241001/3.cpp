// https://atcoder.jp/contests/abc259/tasks/abc259_c
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
    vector<pair<char,ll>> X, Y;
    for (char c : S) {
        if (X.empty() || X.back().first != c) X.push_back({c, 1});
        else X.back().second++;
    }
    for (char c : T) {
        if (Y.empty() || Y.back().first != c) Y.push_back({c, 1});
        else Y.back().second++;
    }
    if (X.size() != Y.size()) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < (int)X.size(); i++) {
        if (X[i].first != Y[i].first) {
            cout << "No\n";
            return;
        }
        if (X[i].second == Y[i].second || (X[i].second < Y[i].second && X[i].second >= 2)) continue;
        cout << "No\n";
        return;
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
