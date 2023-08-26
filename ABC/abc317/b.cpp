#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    for (int i = 0; i < N-1; i++) {
        if (A[i+1] - A[i] > 1) {
            cout << A[i]+1 << endl;
            return 0;
        }
    }

    if (A[0] == 1) cout << A[N-1]+1 << endl;
    else cout << A[0] -1 << endl;
}
