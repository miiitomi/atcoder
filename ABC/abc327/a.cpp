#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    for (int i = 0; i < N-1; i++) {
        if ((S[i] == 'a' && S[i+1] == 'b') || (S[i] == 'b' && S[i+1] == 'a')) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
