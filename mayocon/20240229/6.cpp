// https://atcoder.jp/contests/abc140/tasks/abc140_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        Q[P[i]-1] = i;
    }

    ll ans = 0;
    set<ll> S;
    while (!Q.empty()) {
        int i = Q.back();
        Q.pop_back();
        ll x = P[i];

        if (S.empty()) {
            S.insert(i);
            continue;
        }

        auto iter1 = S.lower_bound(i);
        if (iter1 != S.end()) {
            int l = *iter1, r;
            iter1++;
            if (iter1 == S.end()) r = N;
            else r = *iter1;
            iter1--;

            ll s, t = r - l;

            if (iter1 == S.begin()) s = i + 1;
            else {
                iter1--;
                s = i - *iter1;
                iter1++;
            }

            ans += s * t * x;
        }

        if (iter1 != S.begin()) {
            iter1--;
            int r = *iter1, l;
            if (iter1 == S.begin()) l = 0;
            else {
                iter1--;
                l = *iter1 + 1;
                iter1++;
            }
            iter1++;
            ll s = r - l + 1, t;

            if (iter1 == S.end()) t = N-1 - i + 1;
            else t = *iter1 - 1 - i + 1;

            ans += s * t * x;
        }

        S.insert(i);
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
