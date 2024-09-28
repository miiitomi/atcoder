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
    int i = distance(S.begin(), find(S.begin(), S.end(), 'A'));
    int ans = 0;
    for (char c = 'B'; c <= 'Z'; c++) {
        int j = distance(S.begin(), find(S.begin(), S.end(), c));
        ans += abs(i-j);
        i = j;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
