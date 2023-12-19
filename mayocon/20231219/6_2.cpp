// https://atcoder.jp/contests/abc224/tasks/abc224_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    mint ans = 0, tmp = 1, i2 = ((mint)(2)).inv();

    for (int i = N-1; i >= 0; i--) {
        int x = S[i] - '0';
        ans += x * tmp;
        tmp = (tmp * 10 + 1 ) * i2;
    }

    for (int k = 0; k < N-1; k++) ans *= 2;

    cout << ans.val() << endl;
}
