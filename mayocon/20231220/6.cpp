// https://atcoder.jp/contests/abc171/tasks/abc171_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> p25(2e+6, 1), p26(2e+6, 1), F(2e+6, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}
mint H(int n, int r) {return C(n+r-1, r);}

int main() {
    for (int x = 1; x < 2e+6; x++) {
        p25[x] = p25[x-1] * 25;
        p26[x] = p26[x-1] * 26;
        F[x] = x * F[x-1];
    }

    int K;
    string S;
    cin >> K >> S;
    int N = S.size();

    mint ans = 0;
    for (int m = 0; m <= K; m++) {
        ans += H(N, m) * p25[m] * p26[K-m];
    }
    cout << ans.val() << endl;
}
