#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int M = 1, X = 2;
    while (X < N) {
        M++;
        X *= 2;
    }

    cout << M << endl;

    vector<vector<int>> v(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                v[j].push_back(i+1);
            }
        }
    }
    for (int j = 0; j < M; j++) {
        cout << (int)v[j].size() << " ";
        for (int x : v[j]) cout << x << " ";
        cout << endl;
    }

    string S;
    cin >> S;
    int x = 0, b = 1;
    for (int j = 0; j < M; j++) {
        if (S[j] == '1') {
            x += b;
        }
        b *= 2;
    }
    cout << x+1 << endl;
}
