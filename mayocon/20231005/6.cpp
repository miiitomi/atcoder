// https://atcoder.jp/contests/abc154/tasks/abc154_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
vector<mint> factorial(2e+6 + 10, 1);

mint f(int r, int c) {
    mint ans = 0;
    for (int k = 1; k <= r+1; k++) ans = ans + (factorial[k + c]/(factorial[k]*factorial[c]));
    return ans;
}

int main() {
    for (int k = 2; k < (int)factorial.size(); k++) factorial[k] = factorial[k-1] * k;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    cout << (f(r2, c2) - f(r2, c1 - 1) - f(r1 - 1, c2) + f(r1-1, c1-1)).val() << endl;
}
