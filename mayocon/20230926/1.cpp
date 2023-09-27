// https://atcoder.jp/contests/abc080/tasks/abc080_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int X = N;
    int a = 0;
    while (X != 0) {
        a += X % 10;
        X /= 10;
    }

    if (N  % a == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
