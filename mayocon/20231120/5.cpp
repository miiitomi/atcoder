// https://atcoder.jp/contests/abc119/tasks/abc119_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 2e+18;

int main() {
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    for (int i = 0; i < A; i++) cin >> s[i];
    for (int i = 0; i < B; i++) cin >> t[i];

    vector<ll> min_s(A, INF), min_t(B, INF);
    for (int i = 0; i < A; i++) {
        auto iter = lower_bound(t.begin(), t.end(), s[i]);
        if (iter != t.end()) {
            min_s[i] = min(min_s[i], abs(s[i] - *iter));
        }
        if (iter != t.begin()) {
            iter--;
            min_s[i] = min(min_s[i], abs(s[i] - *iter));
        }
    }

    for (int i = 0; i < B; i++) {
        auto iter = lower_bound(s.begin(), s.end(), t[i]);
        if (iter != s.end()) {
            min_t[i] = min(min_t[i], abs(t[i] - *iter));
        }
        if (iter != s.begin()) {
            iter--;
            min_t[i] = min(min_t[i], abs(t[i] - *iter));
        }
    }

    for (int q = 0; q < Q; q++) {
        ll x;
        cin >> x;
        ll ans = 2e+18;
        int i = distance(s.begin(), lower_bound(s.begin(), s.end(), x));
        if (i < A) ans = min(ans, abs(x - s[i]) + min_s[i]);
        i--;
        if (i >= 0) ans = min(ans, abs(x - s[i]) + min_s[i]);

        int j = distance(t.begin(), lower_bound(t.begin(), t.end(), x));
        if (j < B) ans = min(ans, abs(x - t[j])+min_t[j]);
        j--;
        if (j >= 0) ans = min(ans, abs(x - t[j])+min_t[j]);

        cout << ans << endl;
    }
}
