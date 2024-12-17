// https://atcoder.jp/contests/abc214/tasks/abc214_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());
    reverse(P.begin(), P.end());
    priority_queue<ll, vector<ll>, greater<ll>> R;
    ll tmp = 0;
    while (!P.empty()) {
        auto [l, r] = P.back();
        P.pop_back();
        while (!R.empty() && tmp < l) {
            auto x = R.top();
            R.pop();
            if (x < tmp) {
                cout << "No\n";
                return;
            }
            tmp++;
        }
        tmp = l;
        R.push(r);
    }

    while (!R.empty()) {
        auto x = R.top();
        R.pop();
        if (x < tmp) {
            cout << "No\n";
            return;
        }
        tmp++;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
