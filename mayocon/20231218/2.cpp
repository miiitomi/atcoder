// https://atcoder.jp/contests/abc179/tasks/abc179_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll a = 1; a < N; a++) {
        for (ll b = 1; a*b < N; b++) {
            ll c = N - a * b;
            if (0 < c) ans++;
        }
    }
    cout << ans << endl;
}
