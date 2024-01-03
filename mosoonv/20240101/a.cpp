// https://atcoder.jp/contests/abc289/tasks/abc289_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') S[i] = '1';
        else S[i] = '0';
    }
    cout << S << endl;
}
