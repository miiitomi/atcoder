// https://atcoder.jp/contests/abc148/tasks/abc148_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    if (N < 2 || N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll cnt = 0;
    for (ll x = 5; 2*x <= N; x *= 5) {
        ll y = 2*x;
        cnt += N / y;
    }

    cout << cnt << endl;
}
