// https://atcoder.jp/contests/abc146/tasks/abc146_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> pre(N+1, -1);
    queue<int> Q;
    Q.push(0);
    for (int k = 1; k <= N; k++) {
        while (!Q.empty() && Q.front() <= k-M-1) Q.pop();
        if (S[k] == '1' || Q.empty()) continue;
        pre[k] = Q.front();
        Q.push(k);
    }
    if (pre[N] == -1) cout << -1 << endl;
    else {
        int k = N;
        vector<int> ans;
        while (pre[k] != -1) {
            ans.push_back(k - pre[k]);
            k = pre[k];
        }
        reverse(ans.begin(), ans.end());
        for (int a: ans) cout << a << " ";
        cout << "\n";
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
