// https://atcoder.jp/contests/abc190/tasks/abc190_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll K = 1; 2*N - K*(K-1) >= 1; K++) {
        if ((2*N - K*(K-1)) % (2*K) == 0) {
            ans += 2;
        }
    }

    cout << ans << endl;
}
