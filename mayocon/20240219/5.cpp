// https://atcoder.jp/contests/abc245/tasks/abc245_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> V(N), W(M);
    for (int i = 0; i < N; i++) cin >> V[i].first;
    for (int i = 0; i < N; i++) cin >> V[i].second;
    for (int i = 0; i < M; i++) cin >> W[i].first;
    for (int i = 0; i < M; i++) cin >> W[i].second;
    sort(V.begin(), V.end());
    sort(W.begin(), W.end());
    multiset<int> S;
    while (!V.empty()) {
        int a = V.back().first, b = V.back().second;
        V.pop_back();
        while (!W.empty() && a <= W.back().first) {
            S.insert(W.back().second);
            W.pop_back();
        }
        auto iter = S.lower_bound(b);
        if (iter == S.end()) {
            cout << "No\n";
            return;
        }
        S.erase(iter);
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
