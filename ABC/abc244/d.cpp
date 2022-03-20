#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    map<char, int> mp1, mp2;
    mp1[a]++;
    mp1[b]++;
    mp1[c]++;
    mp2[d]++;
    mp2[e]++;
    mp2[f]++;

    if (mp1 != mp2) {
        cout << "No" << endl;
        return 0;
    }

    if (a == b && b == c) {
        cout << "Yes" << endl;
    } else if (a == b || b == c || c == a) {
        cout << "Yes" << endl;
    } else {
        if (a == d && b == e && c == f) {
            cout << "Yes" << endl;
        } else if (a == f && b == d && c == e) {
            cout << "Yes" << endl;
        } else if (a == e && b == f && c == d) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
