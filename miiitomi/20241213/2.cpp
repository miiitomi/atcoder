// https://atcoder.jp/contests/abc069/tasks/arc080_a
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
    vector<ll> cnt(3, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ll tmp = 0;
        while (a % 2 == 0 && tmp < 2) {
            tmp++;
            a /= 2;
        }
        cnt[tmp]++;
    }
    if (cnt[0] <= cnt[2] || (cnt[0] == cnt[2]+1 && cnt[1] == 0)) cout << "Yes\n";
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
