#include <bits/stdc++.h>
using namespace std;

void shift(string &S) {
    char a = S[0];
    string S_new = "";
    for (int i = 1; i < (int)S.size(); i++) {
        S_new = S_new + S[i];
    }
    S_new = S_new + a;
    S = S_new;
}

int main() {
    set<string> X;
    string S;
    cin >> S;
    X.insert(S);
    for (int i = 0; i < (int)S.size() + 1; i++) {
        shift(S);
        X.insert(S);
    }
    cout << *X.begin() << endl;
    auto iter = X.end();
    iter--;
    cout << *iter << endl;
}
