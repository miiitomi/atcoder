// https://atcoder.jp/contests/abc271/tasks/abc271_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    set<ll> st;
    ll M = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (st.contains(a)) M++;
        else st.insert(a);
    }
    ll ans = 0;
    while (true) {
        if (st.contains(ans+1)) {
            st.erase(ans+1);
            ans++;
            continue;
        }
        if (M >= 2) {
            M -= 2;
            ans++;
            continue;
        }
        if (M == 1) {
            if (st.empty()) {
                cout << ans << endl;
                return;
            }
            auto iter = st.end();
            iter--;
            st.erase(iter);
            M--;
            ans++;
            continue;
        }
        if ((int)st.size() <= 1) {
            cout << ans << endl;
            return;
        }
        for (int k = 0; k < 2; k++) {
            auto iter = st.end();
            iter--;
            st.erase(iter);
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
