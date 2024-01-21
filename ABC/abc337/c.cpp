#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N, -1);
    int s = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        if (A[i] >= 0) {
            B[A[i]] = i;
        } else {
            s = i;
        }
    }

    while (N--) {
        cout << s+1;
        if (N > 0) cout << " ";
        else cout << endl;
        s = B[s];
    }
}
