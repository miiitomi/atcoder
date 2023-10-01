#include <bits/stdc++.h>
using namespace std;

string ABC = "ABC";

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    for (int i = 0; i + 2 < N; i++) {
        bool ok = true;
        for (int j = 0; j < 3; j++) {
            if (S[i + j] != ABC[j]) ok = false;
        }
        if (ok) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
