#include <bits/stdc++.h>
using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int N;
    string T;
    char c;
    cin >> N >> T >> c;

    string S = T;
    int cnt = 0;
    while (S[0] != c) {
        S[0]++;
        if (S[0] > 'z') S[0] = 'a';
        cnt++;
    }

    for (int k = 1; k < N; k++) {
        for (int j = 0; j < cnt; j++) {
            S[k]++;
            if (S[k] > 'z') S[k] = 'a';
        }
    }

    cout << S << endl;
}
