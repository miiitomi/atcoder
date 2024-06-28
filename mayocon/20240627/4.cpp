// https://atcoder.jp/contests/abc216/tasks/abc216_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if (sum <= K) {
        ll ans = 0;
        for (ll &a : A) ans += (1 + a)*a/2;
        cout << ans << endl;
        return;
    }

    ll left = 1, right = ((ll)(2e+9) + 1);
    while (right - left > 1) {
        ll m = (left + right)/2;
        ll cnt = 0;
        for (ll &a : A) cnt += max(0LL, a-m+1);
        if (cnt <= K) right = m;
        else left = m;
    }

    ll ans = 0, cnt = 0;
    priority_queue<ll> PQ;
    for (ll &a : A) {
        if (a >= right) {
            ans += (a+right)*(a-right+1)/2;
            cnt += a-right+1;
            a = right-1;
        }
        if (a > 0) PQ.push(a);
    }

    while (K-cnt > 0 && !PQ.empty()) {
        ll a = PQ.top();
        ans += a;
        a -= 1;
        PQ.pop();
        cnt++;
        if (a > 0) PQ.push(a);
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
