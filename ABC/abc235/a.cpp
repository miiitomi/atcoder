#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    int c = X % 10;
    X /= 10;
    int b = X % 10;
    X /= 10;
    int a = X % 10;
    int ans = 0;
    ans += 100*a + 10*b + c;
    ans += 100*b + 10*c + a;
    ans += 100*c + 10*a + b;
    cout << ans << endl;
}
