#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    map<int, vector<int>> mp;
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Y[i];
        mp[P[i]].push_back(Y[i]);
    }

    for (auto p : mp) sort(mp[p.first].begin(), mp[p.first].end());

    for (int i = 0; i < M; i++) {
        auto iter = lower_bound(mp[P[i]].begin(), mp[P[i]].end(), Y[i]);
        string s, t;
        s = to_string(P[i]);
        t = to_string(1 + distance(mp[P[i]].begin(), iter));
        while (s.size() < 6) s = '0' + s;
        while (t.size() < 6) t = '0' + t;
        cout << s << t << endl;
    }
}
