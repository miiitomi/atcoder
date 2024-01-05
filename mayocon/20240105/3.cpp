// https://atcoder.jp/contests/abc227/tasks/abc227_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll ans = 0;
    for (ll a = 1; a*a*a <= N; a++) {
        for (ll b = a; a*b*b <= N; b++) {
            ll l = b, r = (N / (a*b));
            ans += (r - l + 1);
        }
    }
    cout << ans << endl;
}
