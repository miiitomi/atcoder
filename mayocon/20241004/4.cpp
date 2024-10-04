// https://atcoder.jp/contests/abc114/tasks/abc114_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, ans = 0;
void f(string s) {
    ll x = 0;
    if (s != "") x = stoll(s);
    if (x > N) return;
    bool ok = ((find(s.begin(), s.end(), '3') != s.end()) && (find(s.begin(), s.end(), '5') != s.end()) && (find(s.begin(), s.end(), '7') != s.end()));
    if (ok) ans++;
    f(s + '3');
    f(s + '5');
    f(s + '7');
}

void solve() {
    cin >> N;
    f("");
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
