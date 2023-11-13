// https://atcoder.jp/contests/abc242/tasks/abc242_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll N;
string S;

vector<ll> f(1e+6, 1);

ll rec(ll i) {
    if (i >= N) return 1;
    if (i < N/2 || ( ((N & 1)  && i == N/2))) {
        ll x = (ll)(S[i] - 'A');
        ll ans = x * f[(N - 1)/2 - i ]% MOD;
        ans = (ans + rec(i+1)) % MOD;
        return ans;
    } else {
        if (S[N - 1 - i] < S[i]) return 1;
        else if (S[N-1-i] == S[i]) return rec(i+1);
        else return 0;
    }
}

void solve() {
    cin >> N >> S;
    cout << rec(0) << endl;
}

int main() {
    for (ll x = 1; x < 1e+6; x++) f[x] = 26LL * f[x-1] % MOD;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
