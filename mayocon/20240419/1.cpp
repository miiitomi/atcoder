// https://atcoder.jp/contests/abc203/tasks/abc203_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());

    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        if (K >= (P[i].first - tmp)) {
            K -= P[i].first - tmp;
            tmp = P[i].first;
            K += P[i].second;
        } else {
            break;
        }
    }

    tmp += K;
    cout << tmp << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
