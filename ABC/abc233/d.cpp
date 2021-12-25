#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
    vector<pair<ll, ll>> T(N+1);
    for (int i = 0; i < N+1; i++) {
        T[i].first = S[i];
        T[i].second = i;
    }
    sort(T.begin(), T.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        pair<ll, ll> p1 = make_pair(K + S[i] + 1, -1);
        pair<ll, ll> p2 = make_pair(K + S[i], i+1);
        auto iter1 = lower_bound(T.begin(), T.end(), p1);
        auto iter2 = lower_bound(T.begin(), T.end(), p2);
        ans += distance(iter2, iter1);
    }
    cout << ans << endl;
}
