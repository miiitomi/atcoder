// https://atcoder.jp/contests/abc126/tasks/abc126_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<double> win_prob(2*max(N, K)+1, 0);
    double ans = 0;
    for (int x = 2*max(N, K); x >= 1; x--) {
        if (x >= K) win_prob[x] = 1;
        else win_prob[x] = 0.5 * win_prob[2*x];

        if (x <= N) ans += win_prob[x] / N;
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
