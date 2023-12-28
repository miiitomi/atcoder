// https://atcoder.jp/contests/abc223/tasks/abc223_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    set<string> st;
    int N = S.size();

    for (int i = 0; i < (int)S.size(); i++) {
        string T = "";
        for (int j = 0; j < N; j++) {
            T.push_back(S[(i+j)%N]);
        }
        st.insert(T);
    }

    cout << *st.begin() << endl;
    cout << *st.rbegin() << endl;
}
