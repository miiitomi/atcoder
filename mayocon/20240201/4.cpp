// https://atcoder.jp/contests/abc160/tasks/abc160_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    priority_queue<pair<ll, ll>> Q;
    for (int i = 0; i < A+B+C; i++) {
        ll x;
        cin >> x;
        if (i < A) Q.push(make_pair(x, 0));
        else if (i < A+B) Q.push(make_pair(x, 1));
        else Q.push(make_pair(x, 2));
    }

    ll r = 0, b = 0, t = 0, ans = 0;
    while (r + b + t < X+Y) {
        ll x = Q.top().first;
        ll c = Q.top().second;
        Q.pop();

        if (c == 0) {
            if (r == X) continue;
            r++;
            ans += x;
        } else if (c == 1) {
            if (b == Y) continue;
            b++;
            ans += x;
        } else {
            t++;
            ans += x;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
