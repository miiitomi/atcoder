#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = -10; i <= 10; i++) {
        for (int j = -10; j <= 10; j++) {
            ll X = x1 + i;
            ll Y = y1 + j;
            ll d1 = (X - x1) * (X - x1) + (Y - y1) * (Y - y1);
            ll d2 = (X - x2) * (X - x2) + (Y - y2) * (Y - y2);
            if (d1 == 5 && d2 == 5) {
                cout << "Yes" << endl;
                return 0;   
            }
        }
    }
    cout << "No" << endl;
}
