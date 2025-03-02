#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> V(1e+6);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        V[a].push_back(i);
    }
    int ans = 1e+9;
    for (int a = 0; a < 1e+6; a++) {
        for (int i = 1; i < V[a].size(); i++) {
            ans = min(ans, V[a][i]-V[a][i-1]+1);
        }
    }
    if (ans != (int)1e+9) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
