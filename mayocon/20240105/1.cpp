// https://atcoder.jp/contests/abc216/tasks/abc216_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    char c = S.back();
    S.pop_back();
    S.pop_back();

    if ((int)(c - '0') <= 2) cout << S << "-" << endl;
    else if ((int)(c - '0') <= 6) cout << S << endl;
    else cout << S << "+" << endl;
}
