// https://atcoder.jp/contests/abc158/tasks/abc158_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, P;
    string S;
    cin >> N >> P >> S;
    if (P == 2 || P == 5) {
        ll ans = 0;
        reverse(S.begin(), S.end());
        for (int i = 0; i < N; i++) {
            int x = S[i] - '0';
            if (x % P == 0) {
                ans += (N - i);
            }
        }
        cout << ans << endl;
        return;
    }
    ll tmp = 0, p = 1;
    vector<ll> cnt(P, 0);
    cnt[0]++;
    for (int i = N-1; i >= 0; i--) {
        tmp = (tmp + (S[i]-'0')*p%P) % P;
        cnt[tmp]++;
        p = p*10%P;
    }
    ll ans = 0;
    for (ll x : cnt) ans += x*(x-1)/2;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
