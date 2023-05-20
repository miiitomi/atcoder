#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    ll D;
    cin >> N >> M >> D;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(B.begin(), B.end());
    ll ans = -1;

    for (ll a : A) {
        auto iter1 = lower_bound(B.begin(), B.end(), a - D);
        auto iter2 = lower_bound(B.begin(), B.end(), a + D + 1);
        iter2--;

        if (iter1 <= iter2) {
            ans = max(ans, a + *iter2);
        }
    }

    cout << ans << endl;
}
