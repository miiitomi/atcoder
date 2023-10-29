#include <bits/stdc++.h>
using namespace std;

bool is_ok(int N) {
    int a = N % 10;
    N /= 10;
    int b = N % 10;
    N /= 10;
    int c = N;
    return b*c == a;
}

int main() {
    int N;
    cin >> N;

    for (int x = N; x < 10000; x++) {
        if (is_ok(x)) {
            cout << x << endl;
            return 0;
        }
    }
}
