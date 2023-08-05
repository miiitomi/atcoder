#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<bool> d(N, false);
    for (int i = 0; i < M; i++) {
        d[B[i]] = true;
    }

    int c = -1;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (!d[i]) {
            idx = i;
            c++;
        }
    }
    if (c == 0) cout << idx+1 << endl;
    else cout << -1 << endl;
}
