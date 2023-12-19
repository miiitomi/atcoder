// https://atcoder.jp/contests/abc224/tasks/abc224_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

vector<ll> p(1e+6, 1);
ll f(ll n) {
    if (n < 1) return 1;
    else return p[n];
}

int main() {
    for (int x = 1; x < 1e+6; x++) p[x] = p[x-1] * 2 % MOD;

    string S;
    cin >> S;
    int N = S.size();

    ll ans = 0, tmp = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x = S[i] - '0';
        tmp = (tmp * 10 % MOD + cnt * x % MOD + x * f(i-1) % MOD) % MOD;
        cnt = (cnt + f(i-1)) % MOD;
        ans = (ans + tmp * f(N-i-2)) % MOD;
    }

    cout << ans << endl;
}
