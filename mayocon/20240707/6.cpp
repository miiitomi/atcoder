// https://atcoder.jp/contests/abc346/tasks/abc346_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<vector<ll>> V(26);
    for (int i = 0; i < (int)S.size(); i++) V[S[i]-'a'].push_back(i);

    for (char c : T) {
        if (V[c-'a'].empty()) {
            cout << 0 << endl;
            return;
        }
    }

    ll left = 0, right = (ll)1e+17 + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        ll n = 0, idx = 0;
        for (ll t = 0; t < (int)T.size(); t++) {
            if (n > N) break;

            ll r = mid;
            int c = T[t] - 'a';
            auto iter = lower_bound(V[c].begin(), V[c].end(), idx);
            if (r <= distance(iter, V[c].end())) {
                iter += r-1;
                idx = *iter + 1;
                if (idx == (int)S.size()) {
                    n++;
                    idx = 0;
                }
                continue;
            }
            r -= distance(iter, V[c].end());
            n++;
            ll x = (r - 1) / (ll)V[c].size();
            r -= x * V[c].size();
            n += x;

            iter = V[c].begin() + (r-1);
            idx = *iter + 1;
            if (idx == (int)S.size()) {
                idx = 0;
                n++;
            }
        }

        if (n < N || (n == N && idx == 0)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
