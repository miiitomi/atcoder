#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, a, b, c;
vector<vector<ll>> X;

ll _gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return _gcd(b, a%b);
}

ll _lcm(ll a, ll b) {
    return a * b / _gcd(a, b);
}

ll f(int x, int y, int ng) {
    ll ans;
    ll a1 = X[0][6], a2 = X[0][6];

    ll min_v1 = X[0][6], min_v2 = X[0][6];
    for (int k = 0; k < N; k++) {
        if (k == ng) continue;
        min_v1 = min(min_v1, X[k][x]);
        min_v2 = min(min_v2, X[k][y]);
    }

    ll cnt1 = 0, cnt2 = 0, idx1 = -1, idx2 = -1;
    for (int k = 0; k < N; k++) {
        if (k == ng) continue;
        if (X[k][x] == min_v1) {
            cnt1++;
            idx1 = k;
        }
        if (X[k][y] == min_v2) {
            cnt2++;
            idx2 = k;
        }
    }

    if (cnt1 >= 2 || cnt2 >= 2 || idx1 != idx2) return min_v1 + min_v2;

    ll ans1 = min_v1, ans2 = min_v2;
    min_v2 = X[0][6];
    min_v1 = X[0][6];
    for (int k = 0; k < N; k++) {
        if (k == ng) continue;
        if (k != idx1 && min_v2 > X[k][y]) min_v2 = X[k][y];
        if (k != idx2 && min_v1 > X[k][x]) min_v1 = X[k][x];
    }

    return min(ans1+min_v2, ans2+min_v1);
}

ll g(int x) {
    int y, z;
    if (x == 0) {
        y = 1;
        z = 2;
    } else if (x == 1) {
        y = 2;
        z = 0;
    } else {
        y = 0;
        z = 1;
    }

    ll min_v = X[0][6];
    for (int k = 0; k < N; k++) min_v = min(min_v, X[k][x]);

    ll cnt = 0;
    vector<ll> ngs;
    for (int k = 0; k < N; k++) {
        if (X[k][x] == min_v) {
            cnt++;
            if (cnt >= 3) break;
            ngs.push_back(k);
        }
    }

    if (cnt >= 3) return min_v + f(y, z, -1);

    ll ans = 2e+18;
    for (int idx : ngs) {
        ans = min(ans, min_v + f(y, z, idx));
    }

    return ans;
}

int main() {
    cin >> N >> a >> b >> c;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> v(7);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = _lcm(a, b);
    v[4] = _lcm(b, c);
    v[5] = _lcm(c, a);
    v[6] = _lcm(a, _lcm(b, c));

    X.assign(N, vector<ll>(7, 0));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 7; k++) {
            ll x = v[k];
            if (A[i] % x == 0) {
                continue;
            }
            ll y = (A[i]/x + 1) * x;
            X[i][k] = y - A[i];
        }
    }

    ll ans = X[0][6];
    for (int i = 0; i < N; i++) ans = min(ans, X[i][6]);

    ans = min(ans, f(3, 2, -1));
    ans = min(ans, f(4, 0, -1));
    ans = min(ans, f(5, 1, -1));
    ans = min(ans, g(0));
    ans = min(ans, g(1));
    ans = min(ans, g(2));

    cout << ans << endl;
}
