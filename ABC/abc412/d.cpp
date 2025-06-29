#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, M;
vector<vector<bool>> G;
vector<vector<vector<int>>> VV;
void f(vector<vector<int>> &V, int i) {
    if (i == N) {
        bool ok = true;
        for (auto &v: V) {
            if ((int)v.size() <= 2) {
                ok = false;
                break;
            }
        }
        if (ok) VV.push_back(V);
        return;
    }

    for (int j = 0; j < (int)V.size(); j++) {
        V[j].push_back(i);
        f(V, i+1);
        V[j].pop_back();
    }
    V.push_back(vector<int>(1, i));
    f(V, i+1);
    V.pop_back();
}

void solve() {
    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = true;
        G[b][a] = true;
    }

    {
    vector<vector<int>> V;
    f(V, 0);
    }

    ll ans = INF;
    for (auto &V: VV) {
        ll ans2 = 0;
        for (auto v : V) {
            sort(v.begin(), v.end());
            ll tmp = 0;
            do {
                ll hoge = 0;
                for (int i = 0; i < (int)v.size(); i++) {
                    int s = v[i], t = v[(i+1)%(int)v.size()];
                    if (G[min(s, t)][max(s, t)]) {
                        hoge++;
                    }
                }
                tmp = max(hoge, tmp);
                if ((int)v.size() <= 3) break;
            } while (next_permutation(v.begin(), v.end()));
            ans2 += tmp;
        }
        ans = min(ans, M + N - 2*ans2);
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
