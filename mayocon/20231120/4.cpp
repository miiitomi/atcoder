// https://atcoder.jp/contests/abc160/tasks/abc160_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> p(A), q(B), r(C);
    for (int i = 0; i < A; i++) cin >> p[i];
    for (int i = 0; i < B; i++) cin >> q[i];
    for (int i = 0; i < C; i++) cin >> r[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll ans = 0;
    while (X--) {
        ans += p.back();
        Q.push(p.back());
        p.pop_back();
    }
    while (Y--) {
        ans += q.back();
        Q.push(q.back());
        q.pop_back();
    }

    while (!r.empty() && r.back() > Q.top()) {
        ll s = Q.top();
        ll t = r.back();
        Q.pop();
        r.pop_back();
        Q.push(t);
        ans += t - s;
    }

    cout << ans << endl;
}
