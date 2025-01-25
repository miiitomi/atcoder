#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
};

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    L--; R--;
    vector<ll> A, B, C;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (i < L) A.push_back(a);
        else if (i <= R) B.push_back(a);
        else C.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    CumulativeSum<ll> SA(A), SB(B), SC(C);
    ll M = R-L + 1;
    ll ans = SB.query(0, M);
    for (ll cnt = 1; cnt <= min((ll)A.size(), M); cnt++) {
        ans = min(ans, SA.query(0, cnt)+SB.query(0, M-cnt));
    }
    for (ll cnt = 1; cnt <= min((ll)C.size(), M); cnt++) {
        ans = min(ans, SC.query(0, cnt)+SB.query(0, M-cnt));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
