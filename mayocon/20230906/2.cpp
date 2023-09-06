// https://atcoder.jp/contests/abc212/tasks/abc212_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B.begin(), B.end());
    ll ans = 1e+15;

    for (ll a : A) {
        auto iter = lower_bound(B.begin(), B.end(), a);
        if (iter != B.end()) {
            ans = min(ans, abs(a - *iter));
        }
        if (iter != B.begin()) {
            iter--;
            ans = min(ans, abs(a - *iter));
        }
    }
    cout << ans << endl;
}
