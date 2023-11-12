// https://atcoder.jp/contests/abc269/tasks/abc269_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint998244353;

mint N, M;

mint count(ll a, ll b, ll c, ll d) {
    ll s = (d - c + 1) / 2;
    mint t = s*(s-1);
    
    ll u;
    mint v;
    if ((a + c) % 2 == 1) {
        u = (b - a + 1 + 1) / 2;
        v = (a-1)*M + c+1;
    } else{
        u = (b - a + 1) / 2;
        v = a * M + c + 1;
    }
    mint k = M*u*(u-1) + v*u;

    mint ans = t * u + k * s;

    s = (d-c+1+1)/ 2;
    t = s*(s-1);

    if ((a + c) % 2 == 0) {
        u = (b - a + 1 + 1) / 2;
        v = (a-1)*M + c;
    } else {
        u = (b - a + 1) / 2;
        v = a * M + c;
    }
    k = M*u*(u-1) + v*u;
    ans += t * u + k * s;
    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;
    N = n;
    M = m;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        mint ans = count(a, b, c, d);
        cout << ans.val() << endl;
    }
}
