// https://atcoder.jp/contests/abc259/tasks/abc259_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> m(N);
    vector<vector<ll>> p(N), e(N);
    map<ll, pair<ll,ll>> mp;

    set<vector<pair<int,int>>> S;

    for (int i = 0; i < N; i++) {
        cin >> m[i];
        p[i].resize(m[i]);
        e[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            cin >> p[i][j] >> e[i][j];
            if (!mp.count(p[i][j])) {
                mp[p[i][j]] = make_pair(e[i][j], 0);
            } else {
                mp[p[i][j]].second = max(mp[p[i][j]].second, e[i][j]);
                if (mp[p[i][j]].first < mp[p[i][j]].second) swap(mp[p[i][j]].first, mp[p[i][j]].second);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        vector<pair<int,int>> V;
        for (int j = 0; j < m[i]; j++) {
            if (mp[p[i][j]].first == e[i][j] && mp[p[i][j]].second != e[i][j]) {
                V.push_back(make_pair(p[i][j], e[i][j] - mp[p[i][j]].second));
            }
        }
        S.insert(V);
    }

    cout << (int)S.size() << endl;
}
