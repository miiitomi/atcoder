// https://atcoder.jp/contests/abc247/tasks/abc247_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll Q;
    cin >> Q;

    deque<pair<ll, ll>> D;

    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            ll x, c;
            cin >> x >> c;
            D.push_back(make_pair(x, c));
        } else {
            ll c;
            cin >> c;
            ll ans = 0;
            while (c > 0) {
                auto p = D.front();
                D.pop_front();
                ll m = min(c, p.second);
                ans += m*p.first;
                p.second -= m;
                c -= m;
                if (p.second != 0) D.push_front(p);
            }
            cout << ans << "\n";
        }
    }
}
