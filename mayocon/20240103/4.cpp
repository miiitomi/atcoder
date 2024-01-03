// https://atcoder.jp/contests/abc181/tasks/abc181_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
vector<ll> H, W, S, T;

ll f(ll w) {
    int i = distance(H.begin(), lower_bound(H.begin(), H.end(), w));
    ll ans = 0;
    if (i <= 1) ans = abs(w - H[0]) + T[1];
    else if (i >= N-1) ans = abs(w - H[N-1]) + S[N-2];
    else if (i % 2 == 0) ans = S[i-1] + abs(w - H[i]) + T[i+1];
    else ans = S[i-2] + abs(w - H[i-1]) + T[i];
    return ans;
}

int main() {
    cin >> N >> M;
    H.resize(N);
    W.resize(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int j = 0; j < M; j++) cin >> W[j];
    sort(H.begin(), H.end());

    S.assign(N, 0), T.assign(N, 0);
    for (int i = 1; i < N; i += 2) S[i] += abs(H[i] - H[i-1]);
    for (int i = 1; i < N; i++) S[i] += S[i-1];
    for (int i = N-2; i >= 0; i -= 2) T[i] += abs(H[i] - H[i+1]);
    for (int i = N-2; i >= 0; i--) T[i] += T[i+1];

    ll ans = 1e+18;
    for (ll w : W) ans = min(ans, f(w));
    cout << ans << endl;
}
