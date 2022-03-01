#include <bits/stdc++.h>
using namespace std;

bool is_prime(int N) {
    if (N == 1) return false;
    for (int x = 2; x * x <= N; x++) {
        if (N % x == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    if (is_prime(N)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
