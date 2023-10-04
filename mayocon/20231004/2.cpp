// https://atcoder.jp/contests/abc246/tasks/abc246_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K, X;
    cin >> N >> K >> X;
    priority_queue<ll> A;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ans += a;
        A.push(a);
    }

    while (K > 0 && !A.empty()) {
        ll a = A.top();
        A.pop();
        if (a > X) {
            ll s = min(K, a / X);
            K -= s;
            ans -= s*X;
            a -= s*X;
            if (a > 0) A.push(a);
        } else {
            ans -= a;
            K--;
        }
    }

    cout << ans << endl;
}
