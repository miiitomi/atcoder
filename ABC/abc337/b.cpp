#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int i = 0, N = S.size();

    while (S[i] == 'A' && i < N) {
        i++;
    }

    while (S[i] == 'B' && i < N) {
        i++;
    }

    while (S[i] == 'C' && i < N) {
        i++;
    }

    if (i == N) cout << "Yes\n";
    else cout << "No\n";
}
