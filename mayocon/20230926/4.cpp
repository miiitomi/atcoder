// https://atcoder.jp/contests/abc121/tasks/abc121_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    if (A & 1) {
        ans ^= A;
        A++;
    }

    if (!(B & 1)) {
        ans  ^= B;
    } else {
        B++;
    }

    ll k = (B - A) / 2;

    if (k & 1) ans ^= 1;

    cout << ans << endl;
}
