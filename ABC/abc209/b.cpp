#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int Y = 0;
    for (int i = 0; i < N; i++) {
        Y += A[i];
        if ((i + 1) % 2 == 0) Y--;
    }

    if (Y <= X) cout << "Yes" << endl;
    else cout << "No" << endl;
}
