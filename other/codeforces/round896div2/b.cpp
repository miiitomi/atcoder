#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N, K, A, B;
    cin >> N >> K >> A >> B;
    A--;
    B--;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    ll ans = abs(X[A] - X[B]) + abs(Y[A] - Y[B]);

    ll a_to_m = 1e+18, m_to_b = 1e+18;
    for (int i = 0; i < K; i++) {
        a_to_m = min(a_to_m, abs(X[A] - X[i]) + abs(Y[A] - Y[i]));
        m_to_b = min(m_to_b, abs(X[B] - X[i]) + abs(Y[B] - Y[i]));
    }
    ans = min(ans, a_to_m + m_to_b);
    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
