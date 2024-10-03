// https://atcoder.jp/contests/abc168/tasks/abc168_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X{-INF, 0, INF}, Y{-INF, 0, INF};
    vector<ll> A(N), B(N), C(N), D(M), E(M), F(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        X.push_back(A[i]);
        X.push_back(B[i]);
        Y.push_back(C[i]);
    }
    for (int i = 0; i < M; i++) {
        cin >> D[i] >> E[i] >> F[i];
        X.push_back(D[i]);
        Y.push_back(E[i]);
        Y.push_back(F[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    vector<vector<bool>> S(X.size(), vector<bool>(Y.size(), true)), T(X.size(), vector<bool>(Y.size(), true));
    for (int i = 0; i < max(N, M); i++) {
        if (i < N) {
            A[i] = distance(X.begin(), lower_bound(X.begin(), X.end(), A[i]));
            B[i] = distance(X.begin(), lower_bound(X.begin(), X.end(), B[i]));
            C[i] = distance(Y.begin(), lower_bound(Y.begin(), Y.end(), C[i]));
            for (int j = A[i]; j < B[i]; j++) T[j][C[i]-1] = false;
        }
        if (i < M) {
            D[i] = distance(X.begin(), lower_bound(X.begin(), X.end(), D[i]));
            E[i] = distance(Y.begin(), lower_bound(Y.begin(), Y.end(), E[i]));
            F[i] = distance(Y.begin(), lower_bound(Y.begin(), Y.end(), F[i]));
            for (int j = E[i]; j < F[i]; j++) S[D[i]-1][j] = false;
        }
    }
    vector<vector<bool>> dp(X.size(), vector<bool>(Y.size(), false));
    dp[distance(X.begin(), lower_bound(X.begin(), X.end(), 0))][distance(Y.begin(), lower_bound(Y.begin(), Y.end(), 0))] = true;
    queue<pair<int,int>> Q;
    Q.push({(int)distance(X.begin(), lower_bound(X.begin(), X.end(), 0)), (int)distance(Y.begin(), lower_bound(Y.begin(), Y.end(), 0))});
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        if (S[x][y] && !dp[x+1][y]) {
            int r = x+1, c = y;
            if (r == (int)X.size()-1) {
                cout << "INF\n";
                return;
            }
            dp[r][c] = true;
            Q.push({r, c});
        }
        if (S[x-1][y] && !dp[x-1][y]) {
            int r = x-1, c = y;
            if (r == 0) {
                cout << "INF\n";
                return;
            }
            dp[r][c] = true;
            Q.push({r, c});
        }
        if (T[x][y] && !dp[x][y+1]) {
            int r = x, c = y+1;
            if (c == (int)Y.size()-1) {
                cout << "INF\n";
                return;
            }
            dp[r][c] = true;
            Q.push({r, c});
        }
        if (T[x][y-1] && !dp[x][y-1]) {
            int r = x, c = y-1;
            if (c == 0) {
                cout << "INF\n";
                return;
            }
            dp[r][c] = true;
            Q.push({r, c});
        }
    }

    ll ans = 0;
    for (int x = 0; x < (int)X.size(); x++) {
        for (int y = 0; y < (int)Y.size(); y++) {
            if (!dp[x][y]) continue;
            ans += (X[x+1]-X[x])*(Y[y+1]-Y[y]);
        }
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
