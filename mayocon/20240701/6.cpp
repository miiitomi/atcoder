// https://atcoder.jp/contests/abc203/tasks/abc203_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    map<ll, vector<ll>> mp;
    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        mp[x].push_back(y);
    }
    set<ll> S;
    S.insert(N);

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        vector<ll> &Y = iter->second;
        vector<ll> Remove, Add;
        for (ll y : Y) {
            if (S.count(y)) Remove.push_back(y);
            if (S.count(y-1) || S.count(y+1)) Add.push_back(y);
        }
        for (ll y : Remove) S.erase(y);
        for (ll y : Add) S.insert(y);
    }

    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
