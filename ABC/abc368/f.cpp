#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> G((int)1e+5 + 1, 0);

void pre() {
    set<ll> st;
    for (ll x = 0; x <= (int)1e+5 + 10; x++) {
        st.insert(x);
    }
    for (int x = 2; x <= (int)1e+5; x++) {
        vector<int> v;
        for (int y = 1; y*y <= x; y++) {
            if (x%y != 0) continue;
            v.push_back(y);
            v.push_back(x/y);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.back() == x) v.pop_back();

        for (int y : v) {
            if (st.contains(G[y])) {
                st.erase(G[y]);
            }
        }

        G[x] = *st.begin();

        for (int y : v) {
            st.insert(G[y]);
        }
    }
}

void solve() {
    pre();

    ll N;
    cin >> N;
    int ans = 0;
    while (N--) {
        int a;
        cin >> a;
        ans ^= G[a];
    }

    if (ans == 0) cout << "Bruno\n";
    else cout << "Anna\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
