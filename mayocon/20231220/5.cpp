// https://atcoder.jp/contests/abc255/tasks/abc255_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N-1), X(M);
    for (int i = 0; i < N-1; i++) cin >> S[i];
    for (int j = 0; j < M; j++) cin >> X[j];

    vector<ll> a(N, 0);
    for (int i = 1; i < N; i++) a[i] = S[i-1] - a[i-1];

    vector<ll> b, c;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll y = 0;
            if (i % 2 == 0) y = X[j] - a[i];
            else y = X[j] + a[i];
            ll tmp = 0;
            for (int k = 0; k < M; k++) {
                tmp += distance(lower_bound(b.begin(), b.end(), X[k] - y), lower_bound(b.begin(), b.end(), X[k] - y + 1));
                tmp += distance(lower_bound(c.begin(), c.end(), X[k] + y), lower_bound(c.begin(), c.end(), X[k] + y + 1));
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}
