#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B(N-1,0), C(N-1,0);
    for (int i = 0; i < N-1; i++) {
        if (A[i] <= A[i+1]) B[i] = 1;
        if (A[i] >= A[i+1]) C[i] = 1;
    }
    vector<int> S(N, 0), T(N, 0);
    for (int i = 0; i < N-1; i++) {
        S[i+1] = S[i] + B[i];
        T[i+1] = T[i] + C[i];
    }

    int ans = 1e+9;
    for (int i = 0; i <= N; i++) {
        int tmp;
        if (i == 0) tmp = T[N-1];
        else if (i == N) tmp = S[N-1] + 1;
        else tmp = S[i-1] - S[0] + 1 + T[N-1] - T[i];

        ans = min(ans, tmp);
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}