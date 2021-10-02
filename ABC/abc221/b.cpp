#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i < (int)S.size()-1; i++) {
        swap(S[i], S[i+1]);
        if (S == T) {
            cout << "Yes" << endl;
            return 0;
        }
        swap(S[i], S[i+1]);
    }
    cout << "No" << endl;
}
