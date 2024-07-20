#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, K;

bool contain_kaibun(string s) {
    for (int i = 0; i+K <= N; i++) {
        bool is_kaibun = true;
        for (int j = 0; j < K/2; j++) {
            if (s[i+j] != s[i+K-1-j]) {
                is_kaibun = false;
                break;
            }
        }
        if (is_kaibun) return true;
    }
    return false;
}

void solve() {
    cin >> N >> K;
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    set<string> st;
    do {
        if (!contain_kaibun(S)) {
            st.insert(S);
        }
    } while (next_permutation(S.begin(), S.end()));

    ll ans = st.size();
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
