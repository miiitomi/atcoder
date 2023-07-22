#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool a_ = false;
    bool b_ = false;
    bool c_ = false;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'A') a_ = true;
        if (c == 'B') b_ = true;
        if (c == 'C') c_ = true;

        if (a_ && b_ && c_) {
            cout << i + 1 << endl;
            return 0;
        }
    } 
}
