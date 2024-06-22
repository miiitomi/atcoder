// https://atcoder.jp/contests/abc326/tasks/abc326_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll Y, vector<ll> A) {
    ll N = A.size();
    ll n = A.size()/2;
    map<ll, ll> mp;
    for (ll s = 0; s < (1 << n); s++) {
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1LL << i)) tmp += A[i];
            else tmp -= A[i];
        }
        mp[tmp] = s;
    }

    for (ll t = 0; t < (1 << (N-n)); t++) {
        ll tmp = 0;
        for (int i = 0; i < (N-n); i++) {
            if (t & (1LL << i)) tmp += A[n+i];
            else tmp -= A[n+i];
        }

        if (mp.count(Y - tmp)) {
            return mp[Y-tmp] + (t << n);
        }
    }
    return -1;
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A, B;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (i % 2 == 0) A.push_back(x);
        else B.push_back(x);
    }

    ll s = func(Y, A), t = func(X, B);
    ll stat = 0;

    if (s == -1 || t == -1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    string ans = "";

    for (ll i = 0; i < (ll)A.size(); i++) {
        if (s & (1LL << i)) {
            if (stat == 0) {
                ans.push_back('L');
                stat++;
            } else {
                ans.push_back('R');
                stat--;
            }
        } else {
            if (stat == 0) {
                ans.push_back('R');
                stat = 3;
            } else {
                ans.push_back('L');
                stat++;
            }
        }

        if (i >= (ll)B.size()) break;

        if (t & (1LL << i)) {
            if (stat == 1) {
                ans.push_back('R');
                stat--;
            } else {
                ans.push_back('L');
                stat = 0;
            }
        } else {
            if (stat == 1) {
                ans.push_back('L');
                stat++;
            } else {
                ans.push_back('R');
                stat--;
            }
        }
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
