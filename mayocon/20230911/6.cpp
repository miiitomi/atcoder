// https://atcoder.jp/contests/abc263/tasks/abc263_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 1; i <= N-1; i++) cin >> A[N-i];

    vector<mint> X(N, 0);
    vector<mint> S(N+1, 0);

    for (int i = 1; i <= N-1; i++) {
        int a = A[i];
        mint s = S[i] - S[i-a];
        X[i] = (1 + a + s) / a;
        S[i+1] = S[i] + X[i];
    }

    cout << X[N-1].val() << endl;
}
