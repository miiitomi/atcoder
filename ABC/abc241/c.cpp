#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 6 <= N) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (S[i+k][j] == '.') count++;
                }
                if (count <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if (j + 6 <= N) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (S[i][j+k] == '.') count++;
                }
                if (count <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if (i + 6 <= N && j + 6 <= N) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (S[i+k][j+k] == '.') count++;
                }
                if (count <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            if (i + 6 <= N && j - 5 >= 0) {
                int count = 0;
                for (int k = 0; k < 6; k++) {
                    if (S[i+k][j-k] == '.') count++;
                }
                if (count <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}
