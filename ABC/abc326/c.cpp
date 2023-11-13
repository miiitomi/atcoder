#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    ll ans = -1;
    for (auto iter = A.begin(); iter != A.end(); iter++) {
        auto iter2 = lower_bound(A.begin(), A.end(), *iter + M);
        ans = max(ans, (ll)distance(iter, iter2));
    }

    cout << ans << endl;
}
