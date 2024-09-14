// https://atcoder.jp/contests/abc342/tasks/abc342_a
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
    set<char> st;
    for (char c : S) st.insert(c);
    for (char c : st) {
        int cnt = 0;
        for (char d : S) if (c == d) cnt++;
        if (cnt != 1) continue;
        cout << distance(S.begin(), find(S.begin(), S.end(), c))+1 << endl;
        return;
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
