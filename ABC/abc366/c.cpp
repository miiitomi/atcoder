#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int Q;
    cin >> Q;
    map<int,int> mp;
    int tmp = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            mp[x]++;
            if (mp[x] == 1) tmp++;
        } else if (t == 2) {
            int x;
            cin >> x;
            mp[x]--;
            if (mp[x] == 0) tmp--;
        } else {
            cout << tmp << "\n";
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
