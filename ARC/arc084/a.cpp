#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll b, vector<ll> &A, vector<ll> &C) {
    auto iter1 = lower_bound(A.begin(), A.end(), b);
    auto iter2 = upper_bound(C.begin(), C.end(), b);
    ll ans = distance(A.begin(), iter1);
    ans *= distance(iter2, C.end());
    return ans;
}


int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    for (ll b : B) ans += f(b, A, C);

    cout << ans << endl;
}
