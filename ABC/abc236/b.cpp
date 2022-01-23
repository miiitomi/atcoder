#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(4*N-1);
    for (int i = 0; i < 4*N-1; i++) cin >> A[i];

    vector<int> C(N, 0);
    for (int i = 0; i < 4*N-1; i++) {
        C[A[i]-1]++;
    }

    for (int i = 0; i < N; i++) {
        if (C[i] == 3) {
            cout << i+1 << endl;
            return 0;
        }
    }
}
