#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    int cnt = 0;
    for (int a = 1; a <= 6; a++) {
        for (int b = 1; b <= 6; b++) {
            if (a+b >= X || abs(a-b) >= Y) cnt++;
        }
    }
    cout << fixed << setprecision(15) << cnt/36.0 << endl;
}
