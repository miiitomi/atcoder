// by Rolling-Hash
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> MOD{((ll)1e+9 +7), ((ll)1e+9+9)}, base{100, 100};
vector<vector<ll>> p(2, vector<ll>(3e+6, 1LL)), x, y;

int K = 1;
ll N;
string T, U;

int main() {
    for (int k = 0; k < K; k++) {
        for (int i = 1; i < 3e+6; i++) p[k][i] = p[k][i-1] * base[k] % MOD[k];
    }

    cin >> N >> T;
    U = T;
    reverse(U.begin(), U.end());

    x.assign(2, vector<ll>(2*N+1, 0));
    y.assign(2, vector<ll>(2*N+1, 0));

    for (int k = 0; k < K; k++) {
        for (int i = 0; i < 2*N; i++) {
            x[k][i+1] = (x[k][i] * base[k] + (T[i] - 'a' + 1)) % MOD[k];
            y[k][i+1] = (y[k][i] * base[k] + (U[i] - 'a' + 1)) % MOD[k];
        }
    }

    for (int i = 0; i <= N; i++) {
        bool ok = true;
        for (int k = 0; k < K; k++) {
            ll P = (x[k][2*N] - x[k][i+N]*p[k][N-i]%MOD[k]+ x[k][i]*p[k][N-i]%MOD[k] + MOD[k]) % MOD[k];
            int r = 2*N-1-i, l = 2*N-1-(i+N-1);
            ll Q = (y[k][r+1] - y[k][l]*p[k][N]%MOD[k] + MOD[k]) % MOD[k];
            if (P != Q) ok = false;
        }

        if (ok) {
            string ans = "";
            for (int j = 0; j < N; j++) {
                ans.push_back(T[i+j]);
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
