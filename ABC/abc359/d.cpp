#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

ll K;
vector<ll> ng;
bool is_ng(ll s) {
    bool NG = true;
    for (int i = 0; i < K; i++) {
        bool x = s&(1<<i);
        bool y = s&(1<<(K-1-i));
        if (x != y) NG = false;
    }
    return NG;
}

void solve() {
    ll N;
    cin >> N >> K;

    for (ll s = 0; s < (1 << K); s++) {
        if (is_ng(s)) {
            ng.push_back(s);
        }
    }

    string S;
    cin >> S;
    vector<vector<mint>> dp(N+1, vector<mint>((1 << K), 0));

    for (ll s = 0; s < (1 << K); s++) {
        bool can_be = true;
        for (int i = 0; i < K; i++) {
            if ((S[i] == 'A' && (bool)(s&(1<<i))) || (S[i]=='B' && !((bool)(s&(1<<i))))) can_be = false;
        }
        if (can_be) dp[K][s] = 1;
    }
    for (ll s : ng) dp[K][s] = 0;
    for (int i = K; i < N; i++) {
        for (ll s = 0; s < (1 << K); s++) {
            if (S[i] != 'B') {
                ll t = (s/2);
                dp[i+1][t] += dp[i][s];
            }
            if (S[i] != 'A') {
                ll t = (s/2) + (1 << (K-1));
                dp[i+1][t] += dp[i][s];
            }
        }
        for (ll s : ng) dp[i+1][s] = 0;
    }

    mint ans = 0;
    for (ll s = 0; s < (1 << K); s++) ans += dp[N][s];
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
