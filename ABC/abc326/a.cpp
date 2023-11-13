#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    if (abs(X-Y) <= 2) cout << "Yes" << endl;
    else if (abs(X-Y) >= 4) cout << "No" << endl;
    else if (X < Y) cout << "No" << endl;
    else cout << "Yes" << endl;
}
