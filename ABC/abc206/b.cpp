#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N;
    cin >> N;

    int64_t x = 0;
    int64_t m = 1;

    while (true) {
        x += m;
        if (x >= N) {
            cout << m << endl;
            return 0;
        }
        m++;
    }
}
