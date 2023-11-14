// https://atcoder.jp/contests/abc168/tasks/abc168_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    char c = S[S.size()-1];
    set A{'2', '4', '5', '7', '9'}, B{'0', '1', '6', '8'};

    if (A.count(c)) cout << "hon" << endl;
    else if (B.count(c)) cout << "pon" << endl;
    else cout << "bon" << endl;
}
