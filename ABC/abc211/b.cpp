#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> S(4);
    for (int i = 0; i < 4; i++) cin >> S[i];
    vector<string> A(4);
    A[0] = "H";
    A[1] = "2B";
    A[2] = "3B";
    A[3] = "HR";
    vector<bool> V(4, false);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i] == S[j]) {
                V[i] = true;
            }
        }
    }
    if (V[0] && V[1] && V[2] && V[3]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
