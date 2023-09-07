// https://atcoder.jp/contests/abc158/tasks/abc158_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    deque<char> D;
    for (char c : S) D.push_back(c);
    int Q;
    cin >> Q;
    bool back = true;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) back = !back;
        else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (back) D.push_front(c);
                else D.push_back(c);
            } else {
                if (back) D.push_back(c);
                else D.push_front(c);
            }
        }
    }

    if (back) {
        for (auto iter = D.begin(); iter != D.end(); iter++) cout << *iter;
    } else {
        for (auto iter = D.rbegin(); iter != D.rend(); iter++) cout << *iter;
    }
    cout << endl;
}
