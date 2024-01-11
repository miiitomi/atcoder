// https://atcoder.jp/contests/abc121/tasks/abc121_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> V;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }

    sort(V.begin(), V.end(), [](const auto &a, const auto &b) {return a.first > b.first;});

    ll ans = 0;
    while (M > 0) {
        auto p = V.back();
        V.pop_back();

        ll x = min(M, p.second);
        M -= x;
        ans += x * p.first;
    }

    cout << ans << endl;
}
