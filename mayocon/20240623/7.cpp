// https://atcoder.jp/contests/abc343/tasks/abc343_g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

ll MOD = (ll)1e+9 + 9;
ll b = 200;
vector<ll> p(1e+7, 1);


void f(vector<string> &S, vector<vector<ll>> &TB) {
    int N = S.size();
    vector<vector<ll>> rh(N);
    for (int i = 0; i < N; i++) {
        string s = S[i];
        rh[i].assign(s.size()+1, 0);
        for (int j = s.size()-1; j >= 0; j--) {
            rh[i][j] = ((rh[i][j+1] * b) % MOD + (s[j] - 'a' + 1)) % MOD;
        }
    }

    for (int i = N-1; i >= 0; i--) {
        bool can_erase = false;
        for (int j = 0; j < N; j++) {
            if ((int)S[i].size() > (int)S[j].size() || i == j) continue;
            for (int k = 0; k < (int)S[j].size(); k++) {
                if (k + S[i].size() > S[j].size()) continue;
                if (rh[i][0] == (rh[j][k] - rh[j][k+S[i].size()]*p[S[i].size()]%MOD + MOD) % MOD) {
                    can_erase = true;
                }
            }
        }
        if (can_erase) {
            S.erase(S.begin() + i);
            rh.erase(rh.begin() + i);
            N--;
        }
    }

    TB.assign(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 1; k <= (int)min(S[i].size(), S[j].size()); k++) {
                if (rh[i][S[i].size()-k] == (rh[j][0] - rh[j][k]*p[k]%MOD + MOD)%MOD) {
                    TB[i][j] = k;
                }
            }
        }
    }
}


void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<ll>> TB;
    f(S, TB);
    N = S.size();

    vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        dp[(1 << i)][i] = S[i].size();
    }
    for (int s = 0; s < (1 << N); s++) {
        for (int i = 0; i < N; i++) {
            if (dp[s][i] >= INF/2 || !(s & (1 << i))) continue;
            for (int j = 0; j < N; j++) {
                if (s & (1 << j)) continue;
                dp[s + (1 << j)][j] = min(dp[s + (1 << j)][j], dp[s][i] + (ll)S[j].size() - TB[i][j]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < N; i++) ans = min(ans, dp[(1 << N)-1][i]);
    cout << ans << endl;
}

int main() {
    for (int x = 1; x < 1e+7; x++) p[x] = p[x-1]*b%MOD;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
