// https://atcoder.jp/contests/abc216/tasks/abc216_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<ll> A(N);

bool is_less_than_k(ll m) {
    ll cnt = 0;
    for (ll a : A) cnt += max(0LL, a - m);
    return cnt <= K;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll left = 0;
    ll right = (ll)2e+9 + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (is_less_than_k(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    ll m = right;
    ll ans = 0;
    priority_queue<ll> Q; 
    for (ll &a : A) {
        if (a > m) {
            K -= (a - m);
            ans += (a + m + 1) * (a - m) / 2;
            a = m;
        }
        Q.push(a);
    }

    while (K--) {
        ll a = Q.top();
        Q.pop();
        if (a <= 0) break;
        ans += a;
        a--;
        Q.push(a);
    }

    cout << ans << endl;
}
