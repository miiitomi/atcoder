#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,pair<int,int>>>> V(N);
    dsu U(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int ra = U.leader(a), rb = U.leader(b);
        if (ra == rb) {
            V[ra].push_back({i, {a, b}});
        } else {
            int r = U.merge(ra, rb);
            if (ra != r) {
                if (V[ra].size() > V[r].size()) swap(V[ra], V[r]);
                while (!V[ra].empty()) {
                    V[r].push_back(V[ra].back());
                    V[ra].pop_back();
                }
            }
            if (rb != r) {
                if (V[rb].size() > V[r].size()) swap(V[rb], V[r]);
                while (!V[rb].empty()) {
                    V[r].push_back(V[rb].back());
                    V[rb].pop_back();
                }
            }
        }
    }

    vector<pair<int,pair<int,int>>> ans;
    set<int> leaders, not_empty_leader;
    for (int r = 0; r < N; r++) {
        if (r == U.leader(r)) leaders.insert(r);
        if (!V[r].empty()) not_empty_leader.insert(r);
    }

    while (leaders.size() > 1) {
        int r = *not_empty_leader.begin();
        not_empty_leader.erase(not_empty_leader.begin());

        auto iter = leaders.begin();
        if (*iter == r) iter++;
        int l = *iter;
        auto [i, p] = V[r].back();
        V[r].pop_back();
        ans.push_back({i, {p.first, l}});

        leaders.erase(l);
        leaders.erase(r);
        if (not_empty_leader.contains(l)) not_empty_leader.insert(l);

        int nr = U.merge(r, l);
        leaders.insert(nr);
        if (r != nr) {
            if (V[r].size() > V[nr].size()) swap(V[r], V[nr]);
            while (!V[r].empty()) {
                V[nr].push_back(V[r].back());
                V[r].pop_back();
            }
        }
        if (l != nr) {
            if (V[l].size() > V[nr].size()) swap(V[l], V[nr]);
            while (!V[l].empty()) {
                V[nr].push_back(V[l].back());
                V[l].pop_back();
            }
        }

        if (!V[nr].empty()) not_empty_leader.insert(nr);
    }

    cout  << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        auto [x, p] = ans[i];
        cout << x+1 << " " << p.first+1 << " " << p.second+1 << "\n";
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
