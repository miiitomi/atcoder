// https://atcoder.jp/contests/abc249/tasks/abc249_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    ll ans = 0;
    for (ll st = 1; st < (1 << N); st++) {
        ll tmp = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            ll cnt = 0;
            for (int i = 0; i < N; i++) {
                if (!(st & (1 << i))) continue;
                auto iter = find(S[i].begin(), S[i].end(), c);
                if (iter != S[i].end()) cnt++;
            }
            if (cnt == K) tmp++;
        }
        ans = max(ans, tmp);
    }
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
