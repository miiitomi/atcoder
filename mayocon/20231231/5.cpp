// https://atcoder.jp/contests/abc300/tasks/abc300_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint998244353;

ll N;
map<ll, mint> mp;
mint p = ((mint)(5)).inv();

mint f(ll x) {
    if (mp.count(x)) return mp[x];
    if (x >= N+1) return mp[x] = 0;
    if (x == N) return mp[x] = 1;

    mint a = 0;
    for (ll y = 2; y <= 6; y++) a += f(y*x);
    return mp[x] = a * p;
}

int main() {
    cin >> N;
    cout << f(1).val() << endl;
}
