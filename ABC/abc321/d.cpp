#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, P;
    cin >> N >> M >> P;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(B.begin(), B.end());
    vector<ll> S(M+1, 0);
    for (int i = 0; i < M; i++) S[i+1] = S[i] + B[i];

    ll ans = 0;
    for (ll a : A) {
        ll x = P - a;

        int i = distance(B.begin(), lower_bound(B.begin(), B.end(), x));

        ans += P * (M-i);
        ans += i*a + S[i];
    }

    cout << ans << endl;
}
