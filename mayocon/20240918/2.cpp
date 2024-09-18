// https://atcoder.jp/contests/abc278/tasks/abc278_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, Q;
    cin >> N >> Q;
    map<int, set<int>> mp;
    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            mp[a].insert(b);
        } else if (t == 2) {
            if (mp[a].contains(b)) {
                mp[a].erase(b);
            }
        } else {
            if (mp[a].contains(b) && mp[b].contains(a))  cout << "Yes\n";
            else cout << "No\n";
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
