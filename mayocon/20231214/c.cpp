// https://atcoder.jp/contests/abc181/tasks/abc181_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> C(10, 0);
    for (char c : S) C[c-'0']++;

    if (S.size() == 1) {
        if ((S[0] - '0') % 8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    } else if (S.size() == 2) {
        int x = (S[0] - '0') + 10*(S[1]-'0');
        int y = (S[1] - '0') + 10*(S[0]-'0');
        if (x % 8 == 0 || y % 8 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }


    for (int j = 0; j <= 999; j++) {
        int x = j;
        if (x % 8 != 0) continue;
        bool ok = true;
        vector<int> v = C;
        for (int k = 0; k < 3; k++) {
            int y = x % 10;
            x /= 10;
            if (v[y] == 0) ok = false;
            v[y]--;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
