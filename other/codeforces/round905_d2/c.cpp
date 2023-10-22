#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));
    }

    vector<int> is_last(N, 0);
    vector<bool> S(N, false), T(N, false);
    for (int i = N-1; i >= 0; i--) {
        if (i < N-1) is_last[i] = is_last[i+1];
        if (!S[A[i]]) {
            is_last[i]++;
            S[A[i]] = true;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (!T[A[i]]) {
            ans += is_last[i];
            T[A[i]] = true;
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
