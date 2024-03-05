#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod, b = 100;
vector<ll> p, inv;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = mod, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<ll>> H(N);
    for (int i = 0; i < N; i++) {
        H[i].assign((int)S[i].size()+1, 0);
        for (int j = (int)S[i].size()-1; j >= 0; j--) {
            H[i][j] = (p[S[i].size()-1-j] * (S[i][j] - 'a' + 1) + H[i][j+1]) % mod;
        }
    }

    for (int i = 0; i < N; i++) {
        int M = S[i].size();
        bool can_remove = false;
        for (int j = 0; j < N; j++) {
            if (i == j || (int)S[i].size() > (int)S[j].size()) continue;
            for (int k = 0; k + M <= (int)S[j].size(); k++) if (H[i].front() == (H[j][k]-H[j][k + M]+mod)%mod*inv[H[j].size()-(k+M+1)]%mod) can_remove = true;
        }
        if (can_remove) {
            S.erase(S.begin() + i);
            H.erase(H.begin() + i);
            N--;
            i--;
        }
    }

    vector<vector<int>> d(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int M = min(S[i].size(), S[j].size());
            for (int k = 1; k <= M; k++) {
                if (H[i][H[i].size()-k-1] == (H[j][0] - H[j][k] + mod)%mod*inv[H[j].size()-(k+1)]%mod) d[i][j] = k;
            }
        }
    }

    vector<vector<int>> dp((1 << N), vector<int>(N, 1e+9));
    for (int i = 0; i < N; i++) dp[1 << i][i] = S[i].size();
    for (int s = 1; s < (1 << N)-1; s++) {
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            for (int j = 0; j < N; j++) {
                if (s & (1 << j)) continue;
                dp[s + (1 << j)][j] = min(dp[s + (1 << j)][j], dp[s][i] + (int)S[j].size() - d[i][j]);
            }
        }
    }

    int ans = 1e+9;
    for (int i = 0; i < N; i++) ans = min(ans, dp[(1 << N) - 1][i]);
    cout << ans << "\n";
}

bool is_prime(ll x) {
    for (ll y = 2; y*y <= x; y++) {
        if (x % y == 0) return false;
    }
    return true;
}

void preprocessing() {
    random_device rd;
    mt19937_64 engine(rd());
    uniform_int_distribution<> dist((ll)1e+9, (ll)2e+9);
    do {mod = dist(engine);} while (!is_prime(mod));
    p.assign(1e+6, 1);
    inv.assign(1e+6, 1);
    for (int x = 1; x < 1e+6; x++) {
        p[x] = p[x-1] * b % mod;
        inv[x] = modinv(p[x]);
    }
}

int main() {
    preprocessing();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
