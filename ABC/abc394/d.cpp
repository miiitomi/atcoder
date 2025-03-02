#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S, T= "";
    cin >> S;
    for (char c : S) {
        if (T.empty()) T.push_back(c);
        else if (T.back() == '(' && c == ')') T.pop_back();
        else if (T.back() == '[' && c == ']') T.pop_back();
        else if (T.back() == '<' && c == '>') T.pop_back();
        else T.push_back(c);
    }
    if (T.empty()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
