#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> ans;
    vector<vector<int>> B(N);
    queue<int> Q;
    vector<bool> done(N, false);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        B[a].push_back(i);
        B[b].push_back(i);
        if (a == i || b == i) {
            Q.push(i);
            done[i] = true;
        }
    }

    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        ans.push_back(i);
        for (int j : B[i]) {
            if (!done[j]) {
                done[j] = true;
                Q.push(j);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if ((int)ans.size() != N) cout << -1 << "\n";
    else for (int i : ans) cout << i+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
