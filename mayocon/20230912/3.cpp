// https://atcoder.jp/contests/abc109/tasks/abc109_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        ll y;
        cin >> y;
        A[i] = abs(X - y);
    }

    ll ans = A[0];
    for (int i = 1; i < N; i++) {
        ans = GCD(ans, A[i]);
    }

    cout << ans << endl;
}
