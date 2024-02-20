// https://atcoder.jp/contests/abc300/tasks/abc300_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector<ll> v;
    for (int i = 0; i < N; i++) if (S[i] == 'x') v.push_back(i);

    ll ans = 0;
    for (int s = 0; s <= (int)v.size(); s++) {
        if (s == (int)v.size() && M == 1) break;
        ll R = M-1;
        ll tmp;
        ll t = s;
        if (s == 0) {
            tmp = v[s]+1;
        } else if (s < (int)v.size()) {
            tmp = v[s] - v[s-1];
        } else {
            tmp = N - v.back() - 1 + v[0] + 1;
            R--;
            t = 0;
        }
        ll k = K-1;

        if ((int)v.size()-1 - t <= k) {
            k -= v.size() - 1 - t;
            tmp += N - (v[t] + 1);
        } else {
            tmp += v[t+k+1]-1 - v[t];
            ans = max(ans, tmp);
            continue;
        }

        if (R == 0) {
            ans = max(ans, tmp);
            continue;
        }

        ll m = min(R, k / (ll)v.size());
        tmp += m * N;
        R -= m;
        k -= (ll)v.size() * m;

        if (R == 0) {
            ans = max(ans, tmp);
            continue;
        }

        if (k >= (ll)v.size()) tmp += N;
        else tmp += v[k];
        ans = max(ans, tmp);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
