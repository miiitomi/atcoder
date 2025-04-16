#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    bool is_login = false;
    int cnt = 0;
    while (N--) {
        string s;
        cin >> s;
        if (s == "login") is_login = true;
        else if (s == "logout") is_login = false;
        else if (s == "private") {
            if (!is_login) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
