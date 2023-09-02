#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < N; k++) {
                if (A[k] <= i && i < B[k] && C[k] <= j && j < D[k]) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
