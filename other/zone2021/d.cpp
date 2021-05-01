#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.length();

    vector<char> V(2*n, '_');
    bool right = true;
    int right_index = n;
    int left_index = n-1;

    for (int i = 0; i < n; i++) {
        if (S.at(i) == 'R') {
            right = !right;
        } else if (right) {
            V.at(right_index) = S.at(i);
            right_index++;
        } else if (!right) {
            V.at(left_index) = S.at(i);
            left_index--;
        }
    }

    vector<int> W(n, '_');
    int index = 0;
    for (int i = 0; i < 2*n; i++) {
        int x;
        if (right) {
            x = i;
        } else {
            x = 2*n - 1 - i;
        }

        if (V.at(x) == '_') {
            continue;
        } else if ((index > 0) && (V.at(x) == W.at(index - 1))) {
            W.at(index - 1) = '_';
            index--;
            continue;
        } else {
            W.at(index) = V.at(x);
            index++;
        }
    }

    bool ans = false;

    for (int i = 0; i < n; i++) {
        if (W.at(i) != '_') {
            ans = true;
            string w = "_";
            w.at(0) = W.at(i);
            cout << w;
        } else {
            break;
        }
    }

    if (ans) {
        cout << endl;
    }
}