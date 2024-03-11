// https://atcoder.jp/contests/abc160/tasks/abc160_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<int> V(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int d = abs(i - j);
            d = min(d, abs(i-X) + 1 + abs(Y-j));
            d = min(d, abs(i-Y) + 1 + abs(X-j));
            V[d]++;
        }
    }
    for (int k = 1; k <= N-1; k++) cout << V[k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
