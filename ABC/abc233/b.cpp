#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    string S;
    cin >> S;
    for (int i = 0; i < (int)S.size(); i++) {
        if (i >= L && i <= R) {
            cout << S[(R - i + L)];
        } else {
            cout << S[i];
        }
    }
    cout << endl;
}
