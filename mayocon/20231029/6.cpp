// https://atcoder.jp/contests/abc252/tasks/abc252_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, L;
    cin >> N >> L;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        L -= a;
        Q.push(a);
    }

    if (L > 0) Q.push(L);

    ll ans = 0;
    while (Q.size() >= 2) {
        ll a = Q.top();
        Q.pop();
        ll b = Q.top();
        Q.pop();
        ans += (a + b);
        Q.push(a + b);
    }

    cout << ans << endl;
}
