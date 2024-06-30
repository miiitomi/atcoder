#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        Q[P[i]] = i;
    }
    vector<pair<int,int>> ans;
    for (int x = 0; x < N; x++) {
        int i = Q[x];
        priority_queue<pair<int,int>> PQ;
        for (int y = 0; y < x; y++) {
            if (Q[y] >= i+K) {
                PQ.push({y, Q[y]});
            }
        }

        while (!PQ.empty()) {
            auto [y, j] = PQ.top();
            PQ.pop();
            ans.push_back({i, j});
            swap(Q[P[i]], Q[P[j]]);
            swap(P[i], P[j]);
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
