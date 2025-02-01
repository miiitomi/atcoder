#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, W;
    cin >> N >> W;
    vector<vector<pair<int,int>>> P(W);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        P[x].push_back({y, i});
    }
    int M = N;
    for (int w = 0; w < W; w++) {
        sort(P[w].begin(), P[w].end());
        M = min(M, (int)P[w].size());
    }
    vector<int> T(N+1, 1e+9);
    for (int m = 0; m < M; m++) {
        if (m == 0) T[m] = 1;
        else T[m] = T[m-1]+1;
        for (int w = 0; w < W; w++) {
            int k = P[w][m].first - 1;
            T[m] = max(T[m], k+1);
        }
    }
    vector<int> pos(N);
    for (int w = 0; w < W; w++) {
        for (int i = 0; i < (int)P[w].size(); i++) {
            pos[P[w][i].second] = i;
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, a;
        cin >> t >> a;
        a--;
        if (T[pos[a]] <= t) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
