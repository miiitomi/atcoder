// https://atcoder.jp/contests/abc259/tasks/abc259_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> m(N);
    vector<vector<ll>> p(N), e(N);
    map<ll,pair<ll,ll>> mp;

    for (int i = 0; i < N; i++) {
        cin >> m[i];
        p[i].resize(m[i]);
        e[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            cin >> p[i][j] >> e[i][j];

            if (!mp.count(p[i][j])) {
                mp[p[i][j]] = make_pair(e[i][j], 0);
            } else {
                pair<ll, ll> q = mp[p[i][j]];
                if (q.first < e[i][j]) q = make_pair(e[i][j], q.first);
                else if (q.second < e[i][j]) q.second = e[i][j];
                mp[p[i][j]] = q;
            }
        }
    }

    set<vector<pair<ll,ll>>> S;
    for (int i = 0; i < N; i++) {
        vector<pair<ll,ll>> v;
        for (int j = 0; j < m[i]; j++) {
            pair<ll,ll> q = mp[p[i][j]];
            if ((q.first == e[i][j]) && (q.second < e[i][j])) {
                v.push_back(make_pair(p[i][j], q.second));
            }
        }
        sort(v.begin(), v.end());
        S.insert(v);
    }

    cout << S.size() << endl;
}
