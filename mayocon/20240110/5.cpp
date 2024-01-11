// https://atcoder.jp/contests/abc150/tasks/abc150_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    if (M == 1) {
        if (*min_element(a.begin(), a.end()) == 2 && *max_element(a.begin(), a.end()) == 2) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    ll x = a[0]/2, r = a[0];
    if (x > M) {
        cout << 0 << endl;
        return 0;
    }

    for (int k = 1; k < N; k++) {
        if (r <= M+1) {
            pair<ll, ll> res = ChineseRem(x, r, a[k]/2, a[k]);
            x = res.first;
            r = res.second;
            if (r == -1 || x > M || (x == 0 && r >= M+1)) {
                cout << 0 << endl;
                return 0;
            }
        } else {
            if (x - a[k]/2 < 0 || (x - a[k]/2) % a[k] != 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    if (r >= M+1) {
        if (x == 0) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }

    ll res = max(0LL, (M-x)/r);
    if (x != 0) res++;
    cout << res << endl;
}
