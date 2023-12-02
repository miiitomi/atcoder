#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, a, b;
    cin >> A >> B >> a >> b;

    for (int x = 0; x < 1e+7; x++) {
        if (x % A == a && x % B == b) {
            cout << x << endl;
            return 0;
        }
    }
}
