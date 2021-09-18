#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _abs(ll a) {
    if (a >= 0LL) return a;
    else return -a;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans += _abs(A[i] - B[i]);
    }
    cout << ans << endl;
}
