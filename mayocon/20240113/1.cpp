// https://atcoder.jp/contests/abc256/tasks/abc256_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 1;
    for (ll x = 1; x <= N; x++) ans *= 2;
    cout << ans << endl;
}
