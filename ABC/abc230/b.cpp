#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string T = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";

    for (int i = 0; i < 5; i++) {
        bool yes = true;
        for (int j = 0; j < (int)S.size(); j++) {
            if (T[i + j] != S[j]) {
                yes = false;
                break;
            }
        }
        if (yes) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
