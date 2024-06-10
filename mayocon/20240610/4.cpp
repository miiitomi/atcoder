// https://atcoder.jp/contests/abc216/tasks/abc216_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> a(M);
    vector<vector<int>> top(N);
    queue<int> Q;
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        reverse(a[i].begin(), a[i].end());
        top[a[i].back()].push_back(i);
        if (top[a[i].back()].size() == 2) {
            Q.push(a[i].back());
        }
    }

    int cnt = 0;
    while (!Q.empty()) {
        cnt++;
        int x = Q.front();
        Q.pop();
        for (int l = 0; l < 2; l++) {
            int i = top[x].back();
            top[x].pop_back();
            a[i].pop_back();
            if (a[i].empty()) continue;
            int b = a[i].back();
            top[b].push_back(i);
            if (top[b].size() >= 2) Q.push(b);
        }
    }

    if (cnt == N) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
