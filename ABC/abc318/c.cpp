#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, D, P;
    cin >> N >> D >> P;

    vector<ll> F(N);
    for (int i = 0; i < N; i++) cin >> F[i];
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());

    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + F[i];

    int s = 0;
    ll ans = 0;
    while (s <= N-1) {
        if (S[min(N, s+D)] - S[s] > P) {
            ans += P;
            s += D;
        } else {
            ans += S[N] - S[s];
            break;
        }
    }

    cout << ans << endl;
}
