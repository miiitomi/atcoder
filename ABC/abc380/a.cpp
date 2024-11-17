#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string N;
    cin >> N;
    int one = 0, two = 0, three = 0;
    for (char c : N) {
        int x = c - '0';
        if (x == 1) one++;
        else if (x == 2) two++;
        else if (x == 3) three++;
    }
    if (one == 1 && two == 2 && three == 3) cout << "Yes\n";
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
