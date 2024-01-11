// https://atcoder.jp/contests/abc283/tasks/abc283_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    set<char> st;
    string T;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == '(') {
            T.push_back(c);
        } else if (c == ')') {
            while (T.back() != '(') {
                char d = T.back();
                T.pop_back();
                st.erase(d);
            }
            T.pop_back();
        } else {
            if (st.count(c)) {
                cout << "No" << endl;
                return 0;
            } else {
                T.push_back(c);
                st.insert(c);
            }
        }
    }

    cout << "Yes" << endl;
}
