#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), v(N), B(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v[i] = A[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));

   vector<bool> S(N, false);
    for (int i = 0; i < N; i++) {
        if (!S[A[i]]) {
            S[A[i]] = true;
            B[i+1]++;
        }
        B[i+1] += B[i];
    }

    S.assign(N, false);
    ll ans = 0;
    for (int i = N-1; i >= 0; i--) {
        if (!S[A[i]]) {
            ans += B[i+1];
            S[A[i]] = true;
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
