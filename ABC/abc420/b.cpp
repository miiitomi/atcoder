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
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<int> cnt(N, 0);
    for (int j = 0; j < M; j++) {
        vector<int> V, W;
        for (int i = 0; i < N; i++) {
            if (S[i][j] == '1') V.push_back(i);
            else W.push_back(i);
        }
        if (W.size() < V.size()) swap(V, W);
        for (int x: V) cnt[x]++;
    }
    int a = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < N; i++) {
        if (cnt[i] == a) cout << i+1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
