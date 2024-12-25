// https://atcoder.jp/contests/abc313/tasks/abc313_e
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
    vector<pair<ll, ll>> V;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        if (!V.empty() && V.back().first != 1 && (int)(c - '0') != 1) {
            cout << -1 << endl;
            return;
        }

        if (V.empty() || V.back().first != (ll)(c - '0')) {
            V.push_back({(ll)(c-'0'), 1});
        } else {
            V.back().second++;
        }
    }
    mint ans = 0;
    while ((int)V.size() > 1) {
        if (V.back().first == 1) {
            ans += V.back().second;
            V.pop_back();
        } else {
            ans += 1;
            ll n = V.back().first;
            V.pop_back();
            V.back().second = (V.back().second + (n-1)*ans.val()) % MOD;
        }
    }
    ans += V.back().second - 1;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
