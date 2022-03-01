#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    int a = gcd(X[0], X[1]);
    if (N == 3) a = gcd(a, X[2]);

    set<int> S;
    for (int x = 1; x * x <= a; x++) {
        if (a % x == 0) {
            S.insert(x);
            S.insert(a / x);
        }
    }

    for (auto iter = S.begin(); iter != S.end(); iter++) {
        cout << *iter << endl;
    }
}
