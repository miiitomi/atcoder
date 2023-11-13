// https://atcoder.jp/contests/abc104/tasks/abc104_b
#include <bits/stdc++.h>
using namespace std;

string a = "abcdefghijklmnopqrstuvwxyz";

bool is_ok(string S) {
    if (S[0] != 'A') return false;
    int i = -1;
    for (int j = 0; j < (int)S.size(); j++) {
        if (S[j] == 'C') {
            if (i != -1) return false;
            if (!(2 <= j && j < (int)S.size()-1)) return false;
            i = j;
        }
    }

    if (i == -1) return false;
    
    for (int j = 0; j < (int)S.size(); j++) {
        if (j == 0 || i == j) continue;
        char c = S[j];
        auto it = a.find(c);
        if (!(0 <= it && it <= 25)) return false;
    }
    return true;
}

int main() {
    string S;
    cin >> S;

    if (is_ok(S)) cout << "AC" << endl;
    else cout << "WA" << endl;
}
