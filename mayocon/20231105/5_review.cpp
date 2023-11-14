// https://atcoder.jp/contests/abc242/tasks/abc242_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

vector<ll> p(1e+7, 1);

void solve() {
    int N;
    string S;
    cin >> N >> S;

    if (N == 1) {
        cout << (int)(S[0] - 'A') + 1 << endl;
        return;
    }

    ll ans = 0;
    int m = N/2;
    if (N % 2 == 1) m++;

    for (int i = 0; i < N; i++) {
        ll x = S[i] - 'A';
        if (i < m) {
            ans = (ans + x*p[m-i-1] % MOD) % MOD;
        } else {
            if (S[i] > S[N-1-i]) {
                ans = (ans + 1) % MOD;
                break;
            } else if (S[i] < S[N-1-i]) {
                break;
            } else if (i == N-1) {
                ans = (ans + 1) % MOD;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) p[x] = p[x-1] * 26LL % MOD;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
