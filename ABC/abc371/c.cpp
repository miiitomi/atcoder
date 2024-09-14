#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    ll MG, MH;
    cin >> MG;
    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < MG; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    cin >> MH;
    vector<vector<int>> H(N, vector<int>(N, 0));
    for (int i = 0; i < MH; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        H[u][v] = 1;
        H[v][u] = 1;
    }
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> v(N);
    iota(v.begin(), v.end(), 0);

    ll ans = INF;
    do {
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int a = v[i], b = v[j];
                if (G[i][j] != H[a][b]) tmp += A[a][b];
            }
        }
        ans = min(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));

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
