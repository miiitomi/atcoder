#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    for (int x = 0; x <10000; x += C) {
        if (x >= A && x <= B) {
            cout << x << endl;
            return 0;
        }
        if (x > B) {
            cout << -1 << endl;
            return 0;
        }
    }
}
