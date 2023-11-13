// https://atcoder.jp/contests/abc181/tasks/abc181_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<ll> H, W;

int main() {
    cin >> N >> M;
    H.resize(N);
    W.resize(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> W[i];
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());

    vector<ll> S(N, 0), T(N, 0);
    for (int i = 2; i < N; i += 2) S[i] = S[i-2] + abs(H[i-2] - H[i-1]);
    for (int i = N - 3; i >= 0; i -= 2) T[i] = T[i+2] + abs(H[i+1] - H[i+2]);

    ll ans = 1e+18;
    for (ll w : W) {
        int i = distance(H.begin(), lower_bound(H.begin(), H.end(), w));
        if (i % 2 != 0) i--;
        ans = min(ans, S[i] + T[i] + abs(H[i] - w));
    }

    cout << ans << endl;
}
