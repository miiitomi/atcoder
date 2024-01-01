// https://atcoder.jp/contests/abc164/tasks/abc164_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> S;
    while (N--) {
        string s;
        cin >> s;
        S.insert(s);
    }

    cout << S.size() << endl;
}
