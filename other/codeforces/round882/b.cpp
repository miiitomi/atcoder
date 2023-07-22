#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) M = A[i];
        M = M & A[i];
    }
    int count = 0;
    int start = 0;
    int X;
    for (int i = 0; i < N; i++) {
        if (i == start) X = A[i];
        else X = X & A[i];

        if (X == M) {
            count++;
            start = i+1;
        }
    }

    cout << count << endl;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) solve();
}
