#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> S;
    S.insert("ABC");
    S.insert("ARC");
    S.insert("AGC");
    S.insert("AHC");

    for (int i = 0; i < 3; i++) {
        string T;
        cin >> T;
        S.erase(T);
    }

    for (string s : S) {
        cout << s << endl;
    }
}
