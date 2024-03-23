#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<ll> left_zero(N, 0), left_one(N, 0), right_zero(N, 0), right_one(N, 0);

    if (S[0] == '1') left_zero[0] = C[0];
    else left_one[0] = C[0];
    bool is_one = true;
    for (int i = 1; i < N; i++) {
        left_zero[i] += left_zero[i-1];
        if (is_one && S[i] == '0') left_zero[i] += C[i];
        if (!is_one && S[i] == '1') left_zero[i] += C[i];
        is_one = !is_one;
    }
    is_one = false;
    for (int i = 1; i < N; i++) {
        left_one[i] += left_one[i-1];
        if (is_one && S[i] == '0') left_one[i] += C[i];
        if (!is_one && S[i] == '1') left_one[i] += C[i];
        is_one = !is_one;
    }

    if (S[N-1] == '1') right_zero[N-1] = C[N-1];
    else right_one[N-1] = C[N-1];
    is_one = true;
    for (int i = N-2; i >= 0; i--) {
        right_zero[i] += right_zero[i+1];
        if (is_one && S[i] == '0') right_zero[i] += C[i];
        if (!is_one && S[i] == '1') right_zero[i] += C[i];
        is_one = !is_one;
    }
    is_one = false;
    for (int i = N-2; i >= 0; i--) {
        right_one[i] += right_one[i+1];
        if (is_one && S[i] == '0') right_one[i] += C[i];
        if (!is_one && S[i] == '1') right_one[i] += C[i];
        is_one = !is_one;
    }

    ll ans = 1e+18;
    bool is_even = ((N%2) == 0);

    for (int i = 0; i <= N-2; i++) {
        if (is_even) {
            ans = min(ans, left_zero[i] + right_zero[i+1]);
            ans = min(ans, left_one[i] + right_one[i+1]);
        } else {
            ans = min(ans, left_zero[i] + right_one[i+1]);
            ans = min(ans, left_one[i] + right_zero[i+1]);
        }
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
