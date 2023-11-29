// https://atcoder.jp/contests/abc100/tasks/abc100_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> z[i];

    ll ans = -1;

    for (int s = 0; s < (1 << 3); s++) {
        vector<vector<ll>> v(N, vector<ll>(3, 0));
        for (int i = 0; i < N; i++) {
            v[i][0] = x[i];
            v[i][1] = y[i];
            v[i][2] = z[i];
        }
        for (int k = 0; k < 3; k++) {
            if (s & (1 << k)) {
                for (int i = 0; i < N; i++) v[i][k] *= -1;
            }
        }
        sort(v.begin(), v.end(), [](vector<ll> &p, vector<ll> &q) {return p[0]+p[1]+p[2] > q[0]+q[1]+q[2];});
        
        ll l=0, m=0, n=0;
        for (int i = 0; i < M; i++) {
            l += v[i][0];
            m += v[i][1];
            n += v[i][2];
        }
        ans =max(ans, abs(l) + abs(m) + abs(n));
    }

    cout << ans << endl;
}
