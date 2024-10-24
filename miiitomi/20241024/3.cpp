// https://atcoder.jp/contests/abc053/tasks/arc068_b
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
    vector<ll> cnt(1e+5, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    ll one = 0, more = 0;
    for (ll b : cnt) {
        if (b == 0) continue;
        one++;
        more += b-1;
    }
    more %= 2;
    if (more != 0) {
        more--;
        one--;
    }
    cout << one << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
