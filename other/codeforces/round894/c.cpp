#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (A[0] != N) {
        cout << "NO" << endl;
        return;
    }

    vector<int> B(N, N);
    int j = N-1;
    for (int i = 0; i < N-1; i++) {
        for (int k = A[i]; k > A[i+1]; k--) {
            B[j] = i+1;
            j--;
        }
    }

    if (A == B) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
