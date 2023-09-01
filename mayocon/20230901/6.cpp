// https://atcoder.jp/contests/abc246/tasks/abc246_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    ll ans = 0;
    for (int b = 1; b < (1 << N); b++) {
        vector<int> v(26, 0);
        int num_line = 0;
        for (int k = 0; k < N; k++) {
            if (!(b & (1 << k))) continue;
            num_line++;
            for (char c : S[k]) v[(int)(c - 'a')]++;
        }
        ll num_char = 0;
        for (int c = 0; c < 26; c++) if (v[c] == num_line) num_char++;
        if (num_char == 0) continue;
        ll num_strings = mod_pow(num_char, L);

        if (num_line % 2 == 1) ans = (ans + num_strings) % MOD;
        else ans = (ans - num_strings + MOD) % MOD;
    }

    cout << ans << endl;
}
