// https://atcoder.jp/contests/abc346/tasks/abc346_f
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll N;
string S, T;
vector<vector<ll>> v;

bool is_ok(ll k) {
    if (k > (N*(ll)S.size())/(ll)T.size()) return false;

    ll c = 1, next_idx = 0;
    for (ll j = 0; j < (ll)T.size(); j++) {
        if (c > N+1) return false;
        ll remain = k;
        ll num = T[j] - 'a';
        if (v[num].empty()) return false;
        auto iter = lower_bound(v[num].begin(), v[num].end(), next_idx);
        if (iter != v[num].end()) {
            if ((ll)distance(iter, v[num].end()) >= remain) {
                iter += (k-1);
                next_idx = *iter + 1;
                if (next_idx == (ll)S.size()) {
                    c++;
                    next_idx = 0;
                }
                continue;
            }
            remain -= distance(iter, v[num].end());
        }
        c++;
        next_idx = *v[num].begin();
        if (remain >= (ll)v[num].size()) {
            ll x = remain / v[num].size();
            remain %= (ll)v[num].size();
            if (remain == 0) {
                c += (x-1);
                next_idx = 1 + *v[num].rbegin();
                if (next_idx == (ll)S.size()) {
                    c++;
                    next_idx = 0;
                }
                continue;
            }
            c += x;
        }

        iter = v[num].begin();
        iter += (remain-1);
        next_idx = *iter + 1;
        if (next_idx == (ll)S.size()) {
            c++;
            next_idx = 0;
        }
    }

    if (c <= N || ((c == (N+1)) && (next_idx == 0))) return true;
    else return false;
}

void solve() {
    cin >> N >> S >> T;
    v.resize(26);
    for (ll i = 0; i < (ll)S.size(); i++) {
        v[S[i] - 'a'].push_back(i);
    }

    ll left = 0;
    ll right = 2e+18;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        if (is_ok(mid)) left = mid;
        else right = mid;
    }

    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    ll T = 1;
    // cin >> T;
    while (T--) solve();
}
