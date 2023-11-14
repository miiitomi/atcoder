// https://atcoder.jp/contests/abc255/tasks/abc255_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + A[i];

    for (int q = 0; q < Q; q++) {
        ll x;
        cin >> x;
        int n = distance(A.begin(), lower_bound(A.begin(), A.end(), x));
        ll ans = x*n - (S[n] - S[0]);
        n = distance(lower_bound(A.begin(), A.end(), x+1), A.end());
        ans += S[N] - S[N-n] - x*n;
        cout << ans << endl;
    }
}
