// https://atcoder.jp/contests/abc305/tasks/abc305_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N % 5 == 0) {
        cout << N << endl;
    } else if (abs(N - N / 5 * 5) < abs(N - (N+5)/5*5)) {
        cout << N / 5 * 5 << endl;
    } else {
        cout << (N+5)/5*5 << endl;
    }
}
