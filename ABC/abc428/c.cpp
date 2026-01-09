#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    int tmp = 0;
    vector<unsigned int> m;
    string S = "";
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            S.push_back(c);
            if (c == '(') tmp++;
            else tmp--;
            if (tmp < 0) m.push_back(S.size());
        } else {
            if (!m.empty() && m.back() == S.size()) m.pop_back();
            if (S.back() == '(') tmp--;
            else tmp++;
            S.pop_back();
        }
        if (m.empty() && tmp == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}
