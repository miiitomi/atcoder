// https://atcoder.jp/contests/abc193/tasks/abc193_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)9e+18;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll extGcd(ll a, ll b, ll &p, ll &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    ll d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}


pair<ll, ll> ChineseRem(ll b1, ll m1, ll b2, ll m2) {
  long long p, q;
  long long d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d); // lcm of (m1, m2)
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

void solve() {
    ll X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    ll ans = INF;
    for (ll y = 0; y < Y; y++) {
        for (ll q = 0; q < Q; q++) {
            pair<ll, ll> res = ChineseRem(X+y, 2*(X+Y), P+q, P+Q);
            if (res.second != -1) {
                ans = min(ans, res.first);
            }
        }
    }
    if (ans < INF) cout << ans << endl;
    else cout << "infinity" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
