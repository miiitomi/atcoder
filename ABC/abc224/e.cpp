#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> r(N), c(N);
    map<int, set<int>> X;

    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        r[i] = x;
        c[i] = y;
        X[z].insert(i);
    }

    vector<int> rmax(H, 0), cmax(W, 0), dp(N, 0);
    auto iter = X.end();
    while (iter != X.begin()) {
        iter--;
        for (int i : iter->second) {
            dp[i] = max(rmax[r[i]], cmax[c[i]]);
        }
        for (int i : iter->second) {
            rmax[r[i]] = max(rmax[r[i]], dp[i]+1);
            cmax[c[i]] = max(cmax[c[i]], dp[i]+1);
        }
    }
    for (int i = 0; i < N; i++) cout << dp[i] << endl;
}
