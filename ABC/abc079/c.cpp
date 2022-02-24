#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        X[i] = (int)(S[i] - '0');
    }

    for (int b = 0; b < (1 << N - 1); b++) {
        int s = X[0];
        for (int i = 0; i < N - 1; i++) {
            if (b & (1 << i)) {
                s += X[i + 1];
            } else {
                s -= X[i + 1];
            }
        }
        if (s == 7) {
            cout << X[0];
            for (int i = 0; i < N-1; i++) {
                if (b & (1 << i)) cout << "+";
                else cout << "-";
                cout << X[i + 1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}
