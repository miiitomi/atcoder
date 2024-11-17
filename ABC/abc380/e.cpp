#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    set<tuple<int,int,int>> st;
    for (int i = 0; i <= N+1; i++) st.insert(make_tuple(i, i, i));
    vector<int> cnt(N+2, 1);
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, c;
            cin >> x >> c;
            auto iter = st.lower_bound(make_tuple(x+1, 0, 0));
            iter--;
            auto [l, r, d] = *iter;
            cnt[d] -= (r - l) + 1;
            cnt[c] += (r - l) + 1;
            iter++;
            while (get<2>(*iter) == c) {
                iter = st.erase(iter);
            }
            r = get<0>(*iter) - 1;
            iter--;
            iter--;
            while (get<2>(*iter) == c) {
                iter = st.erase(iter);
                iter--;
            }
            l = get<1>(*iter) + 1;
            iter++;
            st.erase(iter);
            st.insert(make_tuple(l, r, c));
        } else {
            int c;
            cin >> c;
            cout << cnt[c] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
