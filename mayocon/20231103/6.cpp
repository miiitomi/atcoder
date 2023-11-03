// https://atcoder.jp/contests/abc246/tasks/abc246_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    ll N, L;
    cin >> N >> L;
    vector<vector<bool>> A(N, vector<bool>(26, false));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (char c : s) A[i][(int)(c - 'a')] = true;
    }

    ll ans = 0;
    for (ll s = 1; s < (1LL << N); s++) {
        ll cnt = 0;
        vector<bool> a(26, true);
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            cnt++;
            for (int c = 0; c < 26; c++) if (!A[i][c]) a[c] = false;
        }
        ll pos = 1 - 2 *(int)(cnt % 2 == 0);
        ll x = 0;
        for (int c = 0; c < 26; c++) if (a[c]) x++;
        ans = (ans + pos * mod_pow(x, L) + MOD) % MOD;
    }

    cout << ans << endl;
}
