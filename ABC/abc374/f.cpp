#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct TwoDimensionalCumulatedSum {
    int H, W;
    vector<vector<T>> A, S;

    void preprocessing() {
        // Preprocessing of S
        S.assign(H+1, vector<T>(W+1, 0));
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                S[h][w] = A[h-1][w-1] + S[h-1][w] + S[h][w-1] - S[h-1][w-1];
            }
        }
    }

    TwoDimensionalCumulatedSum(vector<vector<T>> &V) {
        H = V.size();
        W = V[0].size();
        A = V;
        preprocessing();
    }

    TwoDimensionalCumulatedSum(int h, int w) {
        H = h;
        W = w;
        A.assign(H, vector<T>(W, 0));
    }

    void set(int h, int w, T x) {
        // If you update A[h][w] with this method, you need run preprocessing() later.
        A[h][w] = x;
    }

    ll query(int hl, int hr, int wl, int wr) {
        // Return the sum of A in [hl, hr) × [wl, wr). (Remark: Semi-opend interval!)
        return S[hr][wr] - S[hl][wr] - S[hr][wl] + S[hl][wl];
    }
};

void solve() {
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> T(N), v;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        for (ll k = 0; k <= N; k++) v.push_back(T[i] + k*X);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll M = v.size();

    vector<vector<ll>> Z(N, vector<ll>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[j] > T[i]) Z[i][j] = v[j]-v[j-1];
        }
    }
    TwoDimensionalCumulatedSum<ll> F(Z);

    vector<vector<ll>> dp(M, vector<ll>(N+1, INF));
    dp[0][0] = 0;
    for (ll i = 0; i+1 < M; i++) {
        ll d = distance(v.begin(), lower_bound(v.begin(), v.end(), v[i]+X));
        for (ll j = 0; j <= N; j++) {
            if (dp[i][j] == INF) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + F.query(j, N, i+1, i+2));
            for (ll h = 1; h <= K; h++) {
                if (d >= M || j + h > N || T[j+h-1] > v[i]) break;
                dp[d][j+h] = min(dp[d][j+h], dp[i][j] + F.query(j+h, N, i+1, d+1));
            }
        }
    }
    cout << dp.back().back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
