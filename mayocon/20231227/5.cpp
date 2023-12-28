// https://atcoder.jp/contests/abc137/tasks/abc137_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> V;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        V.push_back(make_pair(b, a));
    }
    sort(V.begin(), V.end());

    set<ll> S;
    for (int i = 0; i < M; i++) S.insert(i);
    ll ans = 0;
    while (!V.empty()) {
        ll b = V.back().first, a = V.back().second;
        V.pop_back();
        auto iter = S.lower_bound(M-a+1);
        if (iter != S.begin()) {
            ans += b;
            iter--;
            S.erase(iter);
        }
    }

    cout << ans << endl;
}
