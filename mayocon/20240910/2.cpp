// https://atcoder.jp/contests/abc187/tasks/abc187_c
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
    set<string> S, NS;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s[0] == '!') NS.insert(s);
        else S.insert(s);
    }

    for (string s : S) {
        string t = '!' + s;
        if (NS.contains(t)) {
            cout <<s << endl;
            return;
        }
    }

    cout << "satisfiable" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
