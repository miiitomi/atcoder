// https://atcoder.jp/contests/abc298/tasks/abc298_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> v, r(N), c(N), x(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i] >> c[i] >> x[i];
        v.push_back(r[i]);
        v.push_back(c[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        r[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), r[i]));
        c[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), c[i]));
    }
    ll M = v.size();

    vector<ll> R(M, 0), C(M, 0);
    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i < N; i++) {
        R[r[i]] += x[i];
        C[c[i]] += x[i];
        mp[make_pair(r[i], c[i])] = x[i];
    }

    vector<pair<ll, ll>> V;
    for (int i = 0; i < M; i++) V.push_back(make_pair(C[i], i));
    sort(V.begin(), V.end());

    ll ans = -1;
    for (int i = 0; i < M; i++) {
        ll tmp = R[i];
        for (int j = M-1; j >= 0; j--) {
            if (!mp.count(make_pair(i, V[j].second))) {
                ans = max(ans, tmp + V[j].first);
                break;
            }
            ans = max(ans, tmp + V[j].first - mp[make_pair(i, V[j].second)]);
        }
    }

    cout << ans << endl;
}
