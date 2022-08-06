#include <bits/stdc++.h>
using namespace std;

int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    vector<int> v(101, 0);
    for (int i = l1; i <= r1; i++) {
        v[i]++;
    }
    for (int j = l2; j <= r2; j++) {
        v[j]++;
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        if (v[i] == 2) {
            ans++;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    } else {
        cout << ans -1 << endl;
    }
}
