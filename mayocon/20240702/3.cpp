// https://atcoder.jp/contests/abc289/tasks/abc289_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int M;
    cin >> M;
    set<int> S;
    for (int m = 0; m < M; m++) {
        int b;
        cin >> b;
        S.insert(b);
    }
    int X;
    cin >> X;
    vector<bool> dp(X+1, false);
    dp[0] = true;

    for (int x = 0; x < X; x++) {
        if (!dp[x] || S.count(x)) {
            dp[x] = false;
            continue;
        }
        for (int a : A) {
            if (x + a > X) continue;
            dp[x+a] = true;
        }
    }

    if (dp[X]) cout << "Yes\n";
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
