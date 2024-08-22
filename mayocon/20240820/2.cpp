// https://atcoder.jp/contests/abc336/tasks/abc336_c
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
    N--;
    string even = "02468";
    string ans;
    do {
        ans.push_back(even[N%5]);
        N /= 5;
    } while (N);
    reverse(ans.begin(), ans.end());
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
