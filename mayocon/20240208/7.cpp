// https://atcoder.jp/contests/abc318/tasks/abc318_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), L(N), S;
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> L[i];
    for (ll x : X) {
        for (ll l : L) {
            S.push_back(x+l);
            S.push_back(x+l+1);
            S.push_back(x-l);
            S.push_back(x-l-1);
        }
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    sort(L.begin(), L.end());

    vector<bool> can_reach(S.size(), true);
    for (int l = 0; l < (int)S.size(); l++) {
        ll k = S[l];
        vector<ll> Y(N);
        for (int i = 0; i < N; i++) Y[i] = abs(X[i]-k);
        sort(Y.begin(), Y.end());
        for (int j = N-1; j >= 0; j--) {
            if (Y[j] > L[j]) {
                can_reach[l] = false;
                break;
            }
        }
    }

    int l = -1;
    bool now = false;
    ll ans = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (!now && can_reach[i]) {
            now = true;
            l = i;
        }
        if (now && !can_reach[i]) {
            int r = i-1;
            ans += S[r] - S[l] + 1;
            now = false;
        }
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
