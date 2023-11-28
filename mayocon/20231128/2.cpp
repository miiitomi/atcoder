// https://atcoder.jp/contests/abc301/tasks/abc301_c
#include <bits/stdc++.h>
using namespace std;

set<char> atcoder{'a', 't', 'c', 'o', 'd', 'e', 'r'};

int main() {
    string S, T;
    cin >> S >> T;
    vector<int> c(27, 0), d(27, 0);
    for (char s : S) {
        if (s == '@') c[26]++;
        else c[s - 'a']++;
    }
    for (char t : T) {
        if (t == '@') d[26]++;
        else d[t - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        char x = 'a' + i;
        if (!atcoder.count(x)) {
            if (c[i] != d[i]) {
                cout << "No" << endl;
                return 0;
            }
        } else if (c[i] < d[i]) {
            while (c[i] < d[i] && c[26] > 0) {
                c[26]--;
                c[i]++;
            }
        } else if (c[i] > d[i]) {
            while (d[i] < c[i] && d[26] > 0) {
                d[26]--;
                d[i]++;
            }
        }
        if (c[i] != d[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
