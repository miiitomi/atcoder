// https://atcoder.jp/contests/abc324/tasks/abc324_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    string T;
    cin >> N >> T;
    vector<ll> l, r;
    while(N--) {
        string s;
        cin >> s;
        int tmp = 0;

        for (int i = 0; i < (int)s.size() && tmp < (int)T.size(); i++) {
            if (s[i] ==  T[tmp]) tmp++;
        }
        l.push_back(tmp);

        tmp = 0;
        for (int i = 0; i < (int)s.size() && (int)T.size()-1-tmp >= 0; i++) {
            if (s[(int)s.size()-1-i] == T[(int)T.size()-1-tmp]) tmp++;
        }
        r.push_back(tmp);
    }
    ll ans = 0;
    sort(r.begin(), r.end());
    for (ll x : l) {
        auto iter = lower_bound(r.begin(), r.end(), (int)T.size()-x);
        ans += distance(iter, r.end());
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
