// https://atcoder.jp/contests/arc131/tasks/arc131_a
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    string S = "";
    if (B % 2 == 0) S.push_back('0');
    else S.push_back('5');
    B /= 2;
    if (B == 0) S.push_back('0');
    while (B > 0) {
        S.push_back((char)(B % 10 + '0'));
        B /= 10;
    }
    while (A > 0) {
        S.push_back((char)(A % 10 + '0'));
        A /= 10;
    }
    reverse(S.begin(), S.end());
    cout << S << endl;
}
