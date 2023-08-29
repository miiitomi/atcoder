#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    sort(H.begin(), H.end());

    vector<ll> D(N-1, 0);
    for (int i = 0; i < N-1; i++) D[i] = H[i+1] - H[i];

    vector<ll> A(N, 0), B(N, 0);
    for (int i = 1; i < N; i++) {
        A[i] += A[i-1] + (1- (i-1)%2)*D[i-1];
        B[i] += B[i-1] + ((i-1)%2)*D[i-1];
    }

    ll ans = 1e+17;
    for (int t_ = 0; t_ < M; t_++) {
        ll w;
        cin >> w;
        ll tmp = 0;
        int i = (int)distance(H.begin(), lower_bound(H.begin(), H.end(), w));

        if (i > 0) tmp += A[i-1] - A[0];
        
        if (i % 2 == 0) tmp += (H[i] - w);
        else tmp += w - H[i-1];

        if (i < N) tmp += B[N-1] - B[i];

        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
