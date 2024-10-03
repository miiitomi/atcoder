// https://atcoder.jp/contests/abc168/tasks/abc168_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void func(vector<ll> &A, vector<ll> &X) {
    for (ll &a : A) {
        a = distance(X.begin(), lower_bound(X.begin(), X.end(), a));
    }
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N), C(N), D(M), E(M), F(M);
    vector<int> dx{1, 0, -1, 0}, dy{0, -1, 0, 1};
    vector<ll> X{-INF, 0, INF}, Y{-INF, 0, INF};
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
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    func(A, X);
    func(B, X);
    func(C, Y);
    func(D, X);
    func(E, Y);
    func(F, Y);
    vector<vector<vector<bool>>> TO(4, vector<vector<bool>>((int)X.size(), vector<bool>((int)Y.size(), true)));
    for (int i = 0; i < N; i++) {
        for (int x = A[i]; x < B[i]; x++) {
            TO[3][x][C[i]-1] = false;
            TO[1][x][C[i]] = false;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int y = E[i]; y < F[i]; y++) {
            TO[0][D[i]-1][y] = false;
            TO[2][D[i]][y] = false;
        }
    }

    vector<vector<bool>> dp(X.size(), vector<bool>(Y.size(), false));
    int s = distance(X.begin(), lower_bound(X.begin(), X.end(), 0));
    int t = distance(Y.begin(), lower_bound(Y.begin(), Y.end(), 0));
    dp[s][t] = true;
    queue<pair<int,int>> Q;
    Q.push({s, t});
    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            if (!dp[x+dx[k]][y+dy[k]] && TO[k][x][y]) {
                int a = x + dx[k], b = y + dy[k];
                if (a == 0 || a == (int)X.size()-1 || b == 0 || b == (int)Y.size()) {
                    cout << "INF\n";
                    return;
                }
                dp[a][b] = true;
                Q.push({a, b});
            }
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
