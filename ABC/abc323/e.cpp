#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];

    vector<mint> dp(X+1, 0);
    dp[0] = 1;

    mint prob = 1 / (mint)N;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < N; j++) {
            if (i + T[j] <= X) {
                dp[i+T[j]] += prob * dp[i];
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i <= X; i++) {
        if (i + T[0] > X) {
            ans += prob * dp[i];
        }
    }

    cout << ans.val() << endl;
}
