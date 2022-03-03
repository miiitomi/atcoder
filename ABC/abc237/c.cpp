#include <bits/stdc++.h>
using namespace std;

bool kaibun(string &S) {
    int n = S.size();
    for (int i = 0; i < n / 2; i++) {
        if (S[i] != S[n-1-i]) return false;
    }
    return true;
}

int main() {
    string S;
    cin >> S;
    int n = S.size();

    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != 'a') break;
        x++;
    }
    for (int i = 0; i < n; i++) {
        if (S[n-1-i] != 'a') break;
        y++;
    }
    while (y > x) {
        S.pop_back();
        y--;
    }

    if (kaibun(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
