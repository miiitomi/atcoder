#include <bits/stdc++.h>
using namespace std;

void solve() {
    int X, Y, N;
    cin >> X >> Y >> N;
    vector<int> A(N);
    A[N-1] = Y;
    int k = 1;
    for (int i = N-1; i >= 1; i--) {
        A[i-1] = A[i] - k;
        k++;
    }
    if (A[0] < X) cout << -1 << endl;
    else {
        A[0] = X;
        for (int a : A) cout << a << " ";
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}