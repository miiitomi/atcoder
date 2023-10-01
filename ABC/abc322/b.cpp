#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    bool is_settou = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) is_settou = false;
    }

    bool is_setsubi = true;
    for (int i = 0; i < N; i++) {
        if (S[N-1-i] != T[M-1-i]) is_setsubi = false;
    }

    if (is_settou && is_setsubi) cout << 0 << endl;
    else if (is_settou) cout << 1 << endl;
    else if (is_setsubi) cout << 2 << endl;
    else cout << 3 << endl;
}
