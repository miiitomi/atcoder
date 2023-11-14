// https://atcoder.jp/contests/abc152/tasks/abc152_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
vector<int> u, v;
vector<vector<pair<int,int>>> G;
vector<vector<bool>> in_path;

bool dfs(int s, int t, int par, int i) {
    if (s == t) return true;

    for (auto p : G[s]) {
        if (p.first == par) continue;
        int nv = p.first, j = p.second;
        bool done = dfs(nv, t, s, i);
        if (done) {
            in_path[i][j] = true;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }

    cin >> M;
    u.resize(M);
    v.resize(M);
    in_path.assign(M, vector<bool>(N-1, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        u[i] = a;
        v[i] = b;
        dfs(a, b, -1, i);
    }

    ll ans = (1LL << (N-1));
    for (ll s = 1; s < (1 << M); s++) {
        int cnt = 0;
        vector<bool> ip(N-1, false);
        for (int j = 0; j < M; j++) {
            if (!(s & (1LL << j))) continue;
            cnt++;
            for (int i = 0; i < N-1; i++) {
                if (in_path[j][i]) ip[i] = true;
            }
        }
        ll cnt_e = N-1;
        for (int i = 0; i < N-1; i++) if (ip[i]) cnt_e--;
        if (cnt % 2 == 1) ans -= (1LL << cnt_e);
        else ans += (1LL << cnt_e);
    }

    cout << ans << endl;
}
