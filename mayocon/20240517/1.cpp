// https://atcoder.jp/contests/abc192/tasks/abc192_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll g1(ll x) {
    string S = "";
    while (x > 0) {
        S.push_back((x%10) + '0');
        x /= 10;
    }
    sort(S.begin(), S.end());
    ll ans = 0;
    while (!S.empty()) {
        ans = ans * 10 + (ll)(S.back() - '0');
        S.pop_back();
    }
    return ans;
}

ll g2(ll x) {
    string S = "";
    while (x > 0) {
        S.push_back((x%10) + '0');
        x /= 10;
    }
    sort(S.begin(), S.end());
    reverse(S.begin(), S.end());
    ll ans = 0;
    while (!S.empty()) {
        ans = ans * 10 + (ll)(S.back() - '0');
        S.pop_back();
    }
    return ans;
}

ll f(ll x) {
    return g1(x) - g2(x);
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K+1, N);
    for (ll i = 1; i <= K; i++) {
        A[i] = f(A[i-1]);
    }
    cout << A.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
