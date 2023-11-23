// https://atcoder.jp/contests/abc079/tasks/abc079_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(4, 0);
    for (int i = 0; i < 4; i++) {
        char c;
        cin >> c;
        v[i] = (int)(c-'0');
    }

    for (int k = 0; k < (1 << 3); k++) {
        int ans = v[0];
        for (int i = 0; i < 3; i++) {
            if (k & (1 << i)) ans += v[i+1];
            else ans -= v[i+1];
        }

        if (ans == 7) {
            cout << v[0];
            for (int i = 0; i < 3; i++) {
                if (k & (1 << i)) cout << '+';
                else cout << '-';
                cout << v[i+1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}
