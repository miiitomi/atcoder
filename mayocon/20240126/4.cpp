// https://atcoder.jp/contests/abc195/tasks/abc195_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int,int>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    vector<int> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        priority_queue<int> S;
        priority_queue<int, vector<int>, greater<int>> boxes;
        for (int j = 0; j < M; j++) if (j < l || r < j) boxes.push(X[j]);
        int tmp = 0, ans = 0;
        while (!boxes.empty()) {
            while (tmp < N && V[tmp].first <= boxes.top()) {
                S.push(V[tmp].second);
                tmp++;
            }
            if (!S.empty()) {
                ans += S.top();
                S.pop();
            }
            boxes.pop();
        }
        cout << ans << "\n";
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
