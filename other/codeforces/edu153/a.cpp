#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    if (S == "()") {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    if ((int)S.size() == 2) {
        if (S == ")(") cout << "(())" << endl;
        else cout << "()()" << endl;
    } else {
        int a = 0, b = 0;
        int tmp_a = 0, tmp_b = 0;
        for (char c : S) {
            if (c == '(') {
                tmp_a++;
                b = max(b, tmp_b);
                tmp_b = 0;
            } else {
                tmp_b++;
                a = max(a, tmp_a);
                tmp_a = 0;
            }
        }
        a = max(a, tmp_a);
        b = max(b, tmp_b);
        if (max(a, b) > 1) {
            for (int k = 0; k < (int)S.size(); k++) cout << "()";
        } else {
            for (int k = 0; k < (int)S.size(); k++) cout << "(";
            for (int k = 0; k < (int)S.size(); k++) cout << ")";
        }
        cout << endl;
    }

}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
