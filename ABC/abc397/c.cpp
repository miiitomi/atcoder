#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(N+1, 0);
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(A[i]);
        B[i+1] = st.size();
    }
    int ans = -1;
    st.erase(st.begin(), st.end());
    for (int i = N-1; i >= 1; i--) {
        st.insert(A[i]);
        ans = max(B[i] + (int)st.size(), ans);
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
