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
    string s, t;
    cin >> s >> t;
    vector<pair<char, ll>> S, T;
    for (char c : s) {
        if (S.empty() || S.back().first != c) S.push_back({c, 1});
        else S.back().second++;
    }
    for (char c : t) {
        if (T.empty() || T.back().first != c) T.push_back({c, 1});
        else T.back().second++;
    }

    if (S.size() != T.size()) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i].first == T[i].first && (S[i].second == T[i].second || (S[i].second < T[i].second && S[i].second >= 2))) {
            continue;
        } else {
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
