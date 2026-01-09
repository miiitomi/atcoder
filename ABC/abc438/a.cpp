#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, f;
    cin >> d >> f;
    while (f <= d) f += 7;
    cout << f-d << endl;
}
