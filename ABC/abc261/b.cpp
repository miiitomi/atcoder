#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i][j] == 'D') {
                if (A[j][i] != 'D') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            } else if (A[i][j] == 'W') {
                if (A[j][i] != 'L') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            } else {
                if (A[j][i] != 'W') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "correct" << endl;
}
