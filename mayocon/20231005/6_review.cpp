// https://atcoder.jp/contests/abc154/tasks/abc154_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(3e+6, 1);

mint f(int r, int c) {
    return (F[r+c] / (F[r] * F[c]));
}

mint sum(int r, int c) {
    mint ans = 0;
    for (int x = 1; x <= r+1; x++) {
        ans = ans + f(x, c);
    }
    return ans;
}

int main() {
    for (int x = 2; x < 3e+6; x++) F[x] = (x * F[x-1]);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    mint ans = sum(r2, c2) - sum(r2, c1) - sum(r1, c2) + sum(r1, c1);
    cout << ans.val() << endl;
}
