#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
        X[i]--;
    }

    ll sum = 0;
    vector<ll> S(N+1, 0);
    for (int i = 0; i < M-1; i++) {
        int s = min(X[i], X[i+1]), t = max(X[i], X[i+1]);
        ll a = t - s, b = (N + s - t);
        sum += min(a, b);
        if (a < b) {
            ll d = b - a;
            S[s] += d;
            S[t] -= d;

        } else if (b < a) {
            ll d = a - b;
            S[0] += d;
            S[s] -= d;
            S[t] += d;
            S[N] -= d;
        }
    }
    for (int i = 0; i < N; i++) S[i+1] += S[i];
    S.pop_back();

    cout << sum + *min_element(S.begin(), S.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
