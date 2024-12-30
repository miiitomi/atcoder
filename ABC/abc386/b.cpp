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
    reverse(S.begin(), S.end());
    int ans = 0;
    while (!S.empty()) {
        if (S.back() == '0') {
            S.pop_back();
            if (!S.empty() && S.back() == '0') S.pop_back();
        } else {
            S.pop_back();
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}