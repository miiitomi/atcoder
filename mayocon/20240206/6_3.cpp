// https://atcoder.jp/contests/abc118/tasks/abc118_d
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

vector<int> need{(int)1e+9, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    vector<cpp_int> dp(N+1, (int)-1e+9);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] < 0) continue;
        for (int a : A) {
            if (i + need[a] > N) continue;
            cpp_int x = dp[i] * 10 + a;
            if (x > dp[i+need[a]]) dp[i+need[a]] = x;
        }
    }

    cout << dp[N] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
