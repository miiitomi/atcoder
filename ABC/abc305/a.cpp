#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 5 == 0) {
        cout << N << endl;
    } else {
        int l = 5 * (N/5);
        int r = 5 * (N/5) + 5;
        if (abs(N - l) > abs(N - r)) swap(l, r);
        cout << l << endl;
    }
}
