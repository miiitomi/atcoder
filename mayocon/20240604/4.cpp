// https://atcoder.jp/contests/abc112/tasks/abc112_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for (int x = 1; x*x <= M; x++) {
        if (M % x == 0) {
            v.push_back(x);
            v.push_back(M/x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int ans = 0;
    for (int x : v) {
        int y = M/x;
        if (y >= N) {
            ans = max(ans, x);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
