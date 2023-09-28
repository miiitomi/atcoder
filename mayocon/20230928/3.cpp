// https://atcoder.jp/contests/abc289/tasks/abc289_d
#include <bits/stdc++.h>
using namespace std;

int N, M, X;
vector<int> A, B;
vector<int> dp;

int rec(int x) {
    if (dp[x] != -1) return dp[x];

    for (int a : A) {
        if (x - a < 0) break;
        if (rec(x - a) == 1) {
            dp[x] = 1;
            return 1;
        }
    }
    dp[x] = 0;
    return 0;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    B.resize(M);
    for (int i = 0; i < M; i++) cin >> B[i];
    cin >> X;

    dp.assign(X+1, -1);
    dp[0] = 1;
    for (int b : B) dp[b] = 0;

    if (rec(X) == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
