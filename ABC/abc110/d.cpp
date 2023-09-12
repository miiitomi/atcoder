#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(1e+6, 0);

mint C(int n, int r) {
    return F[n] / (F[n-r] * F[r]);
}

mint H(int n, int r) {
    return C(n+r-1, r);
}

int main() {
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < 1e+6; i++) F[i] = F[i-1]*i;

    int N, M;
    cin >> N >> M;

    map<int,int> mp;

    for (int i = 2; i*i <= M; i++) {
        if (M % i == 0) {
            while (M % i == 0) {
                M = M / i;
                mp[i]++;
            }
        }
    }
    if (M != 1) mp[M]++;

    mint ans = 1;
    for (auto p : mp) {
        int r = p.second;
        ans = ans * H(N, r);
    }

    cout << ans.val() << endl;
}
