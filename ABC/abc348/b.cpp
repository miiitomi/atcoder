#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; i++) {
        ll tmp = -1, idx = -1;
        for (int j = 0; j < N; j++) {
            if (tmp < dist(X[i], Y[i], X[j], Y[j])) {
                tmp = dist(X[i], Y[i], X[j], Y[j]);
                idx = j;
            }
        }
        cout << idx+1 << "\n";
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
