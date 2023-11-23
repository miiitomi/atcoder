// https://atcoder.jp/contests/abc172/tasks/abc172_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> f((int)1e+7 + 1, 0);

int main() {
    for (int x = 1; x <= (int)1e+7; x++) {
        for (int y = x; y <= (int)1e+7; y += x) f[y]++;
    }

    ll N;
    cin >> N;

    ll ans = 0;
    for (ll k = 1; k <= N; k++) {
        ans += k * f[k];
    }

    cout << ans << endl;
}
