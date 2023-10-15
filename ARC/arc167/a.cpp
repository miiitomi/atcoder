#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> B(M, 0);
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    for (int i = 0; i < M; i++) {
        B[i] = A[i];
    }

    for (int i = 0; i + M < N; i++) {
        B[M-1-i] += A[M+i];
    }

    ll ans = 0;
    for (ll b : B) ans += b*b;

    cout << ans << endl;
}
