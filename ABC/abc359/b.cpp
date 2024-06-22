#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> B(N);
    for (int i = 0; i < 2*N; i++) {
        int a;
        cin >> a;
        a--;
        B[a].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (B[i][1] - B[i][0] == 2) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
