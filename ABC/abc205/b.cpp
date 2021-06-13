#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    for (int i = 1; i <= N; i++) {
        bool ok = false;
        for (int j = 0; j < N; j++) {
            if (A.at(j) == i) {
                ok = true;
                break;
            }
        }
        if (not ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}