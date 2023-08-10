#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<vector<int> > P(T, vector<int>(3, 0));
    for (int i = 0; i < T; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> P[i][k];
            P[i][k]--;
        }
    }

    int score = 0;
    vector<int> A(20, 0);
    vector<char> C(T, 'A');
    for (int i = 0; i < T; i++) {
        int a = 0;
        int b = 0;
        for (int k = 0; k < 3; k++) {
            if (A[P[i][k]] == -1) a++;
            else if (A[P[i][k]] == 1) b++;
        }
        for (int k = 0; k < 3; k++) {
            if (a >= b) A[P[i][k]]++;
            else {
                A[P[i][k]]--;
                C[i] = 'B';
            }
        }
        for (int j = 0; j < 20; j++) {
            if (A[j] == 0) score++;
        }
    }

    // for (int i = 0; i < T; i++) cout << C[i] << endl;
    cout << score << endl;
}
