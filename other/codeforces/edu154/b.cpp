#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < (int)a.size()-1; i++) {
        if (a[i] == '0' && b[i] == '0' && a[i+1] == '1' && b[i+1] == '1') {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
