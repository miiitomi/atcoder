#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), V(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ans += A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        V[i] = B[i] - A[i];
    }
    sort(V.begin(), V.end());
    while (!V.empty() && V.back() > 0 && K > 0) {
        ans += V.back();
        V.pop_back();
        K--;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
