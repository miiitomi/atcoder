#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

ll mod_pow(ll a, ll n, ll MOD) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2, MOD);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

void f(int N, string &S) {
    int k = (N - 1) / 2;
    ll ans = 0;
    string T = S;
    for (int i = 0; i < k; i++) {
        ans += (ll)(S[i] - 'A') * mod_pow(26, k-i, MOD);
        ans %= MOD;
        T[N-1-i] = T[i];
    }
    T[N-1-k] = T[k];

    if (T <= S) {
        ans = (ans + (int)(S[k] - 'A') + 1) % MOD;
    } else {
        ans = (ans + (int)(S[k] - 'A')) % MOD;
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        f(N, S);
    }
}
