// https://atcoder.jp/contests/abc275/tasks/abc275_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> mp;

ll f(ll x) {
    if (x <= 0) return 1;
    if (mp.count(x)) return mp[x];
    mp[x] = f(x / 2) + f(x / 3);
    return mp[x];
}

int main() {
    ll N;
    cin >> N;
    cout << f(N) << endl;
}
