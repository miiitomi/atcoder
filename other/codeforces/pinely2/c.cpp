#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1);
    vector<bool> used(N+1, false);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        used[A[i]] = true;
    }
    for (int i = 0; i <= N; i++) if (!used[i]) A[N] = i;

    K = K % (N+1);
    vector<int> b(N+1);
    for (int i = 0; i <= N; i++) {
        b[(i+K)%(N+1)] = A[i];
    }

    for (int i = 0; i < N; i++) cout << b[i] << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}