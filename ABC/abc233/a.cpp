#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    if (X >= Y) {
        cout << 0 << endl;
    } else if ((Y - X) % 10 == 0) {
        cout << (Y - X) / 10 << endl;
    } else {
        cout << 1 + (Y - X) / 10 << endl;
    }
}
