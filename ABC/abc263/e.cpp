#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = N-1; i >= 1; i--) cin >> A[i];

    vector<mint> V(N, 0);
    vector<mint> S(N+1, 0);

    for (int i = 1; i < N; i++) {
        S[i] = S[i-1] + V[i-1];
        V[i] = (A[i] + 1 + S[i] - S[i - A[i]]) / A[i];
    }

    cout << V[N-1].val() << endl;
}
