// https://atcoder.jp/contests/abc304/tasks/abc304_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

void solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> V;
    for (int x = 1; x < N; x++) if (N % x == 0) V.push_back(x);
    vector<ll> ans(V.size(), 0);

    for (int i = 0; i < (int)V.size(); i++) {
        int m = V[i];
        vector<bool> aki(m, false);
        for (int j = 0; j < N; j++) {
            if (S[j] == '.') aki[j % m] = true;
        }
        ll cnt = 0;
        for (int j = 0; j < m; j++) if (!aki[j]) cnt++;
        ll tmp = mod_pow(2LL, cnt);
        for (int j = 0; j < i; j++) {
            int x = V[j];
            if (m % x == 0) tmp = (tmp - ans[j] + MOD) % MOD;
        }
        ans[i] = tmp;
    }

    ll answer = 0;
    for (ll a : ans) answer = (answer + a) % MOD;
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
