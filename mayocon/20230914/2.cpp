// https://atcoder.jp/contests/abc121/tasks/abc121_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> X(N);
    for (int i = 0; i < N; i++) cin >> X[i].first >> X[i].second;
    sort(X.begin(), X.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a = X[i].first, b = X[i].second;
        if (M > b) {
            ans += b*a;
            M -= b;
        } else {
            ans += M*a;
            break;
        }
    }
    cout << ans << endl;
}
