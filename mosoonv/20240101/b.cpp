// https://atcoder.jp/contests/abc081/tasks/abc081_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cnt = 0;
    for (char s : S) if (s == '1') cnt++;
    cout << cnt << endl;
}
