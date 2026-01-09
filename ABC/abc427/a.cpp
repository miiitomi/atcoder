#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i != N/2) cout << S[i];
    }
    cout << "\n";
}
