#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extended_gcd(b, a%b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    extended_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}
