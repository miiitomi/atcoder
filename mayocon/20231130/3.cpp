// https://atcoder.jp/contests/abc060/tasks/abc060_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int x = A % B;
    vector<bool> dp(B, false);

    while (!dp[x]) {
        dp[x] = true;
        x = (x + A) % B;
    }

    if (dp[C]) cout << "YES" << endl;
    else cout << "NO" << endl;
}
