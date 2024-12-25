// https://atcoder.jp/contests/abc275/tasks/abc275_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<string> S(9);
    vector<pair<int,int>> V;
    for (int i = 0; i < 9; i++) {
        cin >> S[i];
        for (int j = 0; j < 9; j++) {
            if (S[i][j] == '#') V.push_back({i,j});
        }
    }
    set<vector<pair<int,int>>> st;
    for (int i = 0; i < V.size(); i++) {
        for (int j = i+1; j < V.size(); j++) {
            for (int k = j+1; k < V.size(); k++) {
                int x1 = V[j].first-V[i].first, y1 = V[j].second - V[i].second;
                int x2 = V[k].first - V[i].first, y2 = V[k].second - V[i].second;
                if (x1*x1+y1*y1 != x2*x2+y2*y2 || x1*x2+y1*y2 != 0) continue;
                int a = V[i].first + x1 + x2, b = V[i].second + y1 + y2;
                if (0 <= a && a < 9 && 0 <= b && b < 9 && S[a][b] == '#') {
                    vector<pair<int,int>> W{V[i], V[j], V[k], make_pair(a, b)};
                    sort(W.begin(), W.end());
                    st.insert(W);
                }
            }
        }
    }
    cout << st.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
