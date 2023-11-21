// https://atcoder.jp/contests/abc106/tasks/abc106_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    K--;

    ll i = 2e+18;
    for (int j = 0; j < (int)S.size(); j++) {
        if (S[j] != '1') {
            i = j;
            break;
        }
    }

    if (K < i) cout << '1' << endl;
    else cout << S[i] << endl;
}
