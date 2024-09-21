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
    string S;
    cin >> S;
    set<ll> st;
    for (int i = 0; i < (int)S.size()-2; i++) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') st.insert(i);
    }
    while (Q--) {
        ll x;
        char c;
        cin >> x >> c;
        x--;
        S[x] = c;
        for (int i = max(0LL, x-2); i <= x; i++) {
            if (st.contains(i)) st.erase(i);
            if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') st.insert(i);
        }
        cout << st.size() << "\n";
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
