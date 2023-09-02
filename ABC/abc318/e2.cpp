// 別解（公式解説）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    ll sum = 0;
    vector<ll> L(N+1, 0), R(N+1, 0);
    for (int a : A) R[a]++;
    R[A[0]]--;

    for (int i = 1; i < N-1; i++) {
        ll x = A[i-1];
        ll y = A[i];

        if (x == y) {
            sum -= L[x]*R[x];
            L[x]++;
            R[x]--;
            sum += L[x]*R[x];
            ans += sum - L[x]*R[x];
        } else {
            sum -= L[x]*R[x] + L[y]*R[y];
            L[x]++;
            R[y]--;
            sum += L[x]*R[x] + L[y]*R[y];
            ans += sum - L[y]*R[y];
        }
    }

    cout << ans << endl;
}
