// https://atcoder.jp/contests/abc215/tasks/abc215_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end());
    ll left = 0, right = (ll)(1e+9) + 1;

    while (right - left > 1) {
        ll mid = (right + left) / 2;
        bool exists = false;
        ll mi = INF, ma = -INF;
        int l = 0;
        for (pair<ll,ll> &p : P) {
            while (l < N && P[l].first <= p.first-mid) {
                mi = min(mi, P[l].second);
                ma = max(ma, P[l].second);
                l++;
            }
            if (mi <= p.second-mid || p.second+mid <= ma) {
                exists = true;
                break;
            }
        }
        if (exists) left = mid;
        else right = mid;
    }

    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
