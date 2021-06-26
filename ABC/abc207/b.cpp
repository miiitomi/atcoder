#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;

    if (C * D - B <= 0) {
        cout << -1 << endl;
        return 0;
    }

    if (A % (C * D - B) == 0) {
        cout << A / (C * D - B) << endl;
    } else {
        cout << (A / (C * D - B)) + 1 << endl;
    }
}
