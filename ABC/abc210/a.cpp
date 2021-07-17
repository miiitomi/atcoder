#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;
    if (N <= A) {
        cout << X * N << endl;
    } else {
        cout << (A * X) + (N - A) * Y << endl;
    }
}
