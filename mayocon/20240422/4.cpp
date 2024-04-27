// https://atcoder.jp/contests/abc188/tasks/abc188_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, C;
    cin >> N >> C;
    vector<vector<ll>> a(N, vector<ll>(3, 0));
    for (int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][1]++;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    ll ans = 0;
    ll tmp_sum = 0;
    ll last_day = 0;
    while (!a.empty()) {
        ans += min(C, tmp_sum) * (a.back()[0] - last_day);
        tmp_sum += a.back()[2];
        Q.push(make_pair(a.back()[1], a.back()[2]));
        last_day = a.back()[0];
        a.pop_back();

        while (!Q.empty() && (a.empty() || a.back()[0] > Q.top().first)) {
            ans += min(C, tmp_sum) * (Q.top().first - last_day);
            last_day = Q.top().first;
            tmp_sum -= Q.top().second;
            Q.pop();
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
