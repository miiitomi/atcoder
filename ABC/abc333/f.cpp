#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int N;
vector<mint> p2(5000, 1), i2(5000, 1), F(5000, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}

int main() {
    for (int x = 1; x < 5000; x++) {
        p2[x] = p2[x-1] * 2;
        i2[x] = p2[x].inv();
        F[x] = F[x-1] * x;
    }

    cin >> N;
    vector<mint> dp(N+1, 1);
    for (int K = 2; K <= N; K++) {
        mint tmp = 0;
        for (int j = 1; j <= K-1; j++) tmp += C(K-1, j)*dp[K-j];
        dp[K] = tmp * i2[K] * (1 - i2[K]).inv();
    }

    for (int i = 1; i <= N; i++) {
        mint tmp = 0;
        for (int j = 0; j <= i-1; j++) tmp += C(i-1, j) * dp[N-j];
        tmp *= i2[i-1];
        cout << tmp.val() << " ";
    }
    cout << endl;
}
