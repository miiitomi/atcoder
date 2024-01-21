#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int X = 0, Y = 0;
    while (N--) {
        int x, y;
        cin >> x >> y;
        X += x;
        Y += y;
    }

    if (X > Y) cout << "Takahashi\n";
    else if (X == Y) cout << "Draw\n";
    else cout << "Aoki\n";
}
