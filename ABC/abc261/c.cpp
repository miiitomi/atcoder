#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> M;

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        if (M.count(S)) {
            cout << S << "(" << M[S] << ")" << endl;
            M[S]++;
        } else {
            cout << S << endl;
            M[S]++;
        }
    }
}
