// https://atcoder.jp/contests/abc239/tasks/abc239_d
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for (int x = A; x <= B; x++) {
        bool win = true;
        for (int y = C; y <= D; y++) {
            if (is_prime(x + y)) {
                win = false;
                break;
            }
        }
        if (win) {
            cout << "Takahashi" << endl;
            return 0;
        }
    }   

    cout << "Aoki" << endl;
}
