// https://atcoder.jp/contests/abc085/tasks/abc085_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    set<int> st;
    cin >> N;
    while (N--) {
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
}
