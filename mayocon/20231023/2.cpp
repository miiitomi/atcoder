// https://atcoder.jp/contests/abc044/tasks/abc044_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<int,int> M;
    for (char c : S) M[c]++;

    for (auto iter = M.begin(); iter != M.end(); iter++) {
        if (iter->second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
