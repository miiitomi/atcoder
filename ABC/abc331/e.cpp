#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, L;
    cin >> N >> M >> L;
    vector<pair<ll, ll>> a(N), b(M);
    vector<ll> c(N), d(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i;
        c[i] = a[i].first;
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i].first;
        b[i].second = i;
        d[i] = b[i].first;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    set<pair<ll,ll>> S;
    for (int i = 0; i < L; i++) {
        ll p, q;
        cin >> p >> q;
        p--;
        q--;
        S.insert(make_pair(p, q));
    }

    ll left = 0, right = 2e+9;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll cnt = 0;
        for (ll x : c) {
            ll y = distance(lower_bound(d.begin(), d.end(), mid - x), d.end());
            cnt += y;
        }
        if (cnt >= L+1) {
            left = mid;
        } else {
            right = mid;
        }
    }

    vector<pair<ll, pair<ll,ll>>> v;

    for (int i = 0; i < N; i++) {
        ll s = a[i].second;
        ll x = a[i].first;
        int j = M-1;
        while (j >= 0 && b[j].first + x >= left) {
            v.push_back(make_pair(x + b[j].first, make_pair(s, b[j].second)));
            j--;
        }
    }

    sort(v.begin(), v.end());

    while (true) {
        ll ans = v.back().first;
        pair<ll, ll> p = v.back().second;
        v.pop_back();
        if (!S.count(p)) {
            cout << ans << endl;
            return 0;
        }
    }
}
