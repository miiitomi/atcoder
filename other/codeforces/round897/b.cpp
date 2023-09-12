#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K = 0;
    for (int i = 0; i < N/2; i++) if (S[i] != S[N-1-i]) K++;

    string T(N+1, '0');

    bool b = true;
    for (int i = K; i <= N/2; i++) {
        if (b) T[i] = '1';
        if (N % 2 == 0) b = !b;
    }
    for (int i = 0; i <= N/2; i++) {
        T[N-i] = T[i];
    }

    cout << T << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
