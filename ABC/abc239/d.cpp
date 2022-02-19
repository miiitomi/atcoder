#include <bits/stdc++.h>
using namespace std;

bool is_prime(int N) {
    if (N <= 1) return false;
    for (int i = 2; i*i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for (int x = A; x <= B; x++) {
        bool all_non_prime = true;
        for (int y = C; y <= D; y++) {
            if (is_prime(x + y)) all_non_prime = false;
        }
        if (all_non_prime) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }
    cout << "Aoki" << endl;
}
