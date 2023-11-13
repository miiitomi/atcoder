#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(2*N);
    for (int i = 0; i < 2*N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = (A[N-1] - A[0]) + (A[2*N-1] - A[N]);
    cout << ans << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << " " << A[N+i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
