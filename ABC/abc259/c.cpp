#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    if (S.size() > T.size() || S[0] != T[0]) {
        cout << "No" << endl;
        return 0;
    }

    vector<pair<char, int>> V_T;
    V_T.push_back(make_pair(T[0], 1));
    int j = 0;
    for (int i = 1; i < T.size(); i++) {
        char t = T[i];
        if (t != V_T[j].first) {
            V_T.push_back(make_pair(t, 1));
            j++;
        } else {
            V_T[j].second++;
        }
    }

    vector<pair<char, int>> V_S;
    V_S.push_back(make_pair(S[0], 1));
    j = 0;
    for (int i = 1; i < S.size(); i++) {
        char s = S[i];
        if (s != V_S[j].first) {
            V_S.push_back(make_pair(s, 1));
            j++;
        } else {
            V_S[j].second++;
        }
    }

    if (V_T.size() != V_S.size()) {
        cout << "No" << endl;
        return 0;
    } else {
        for (int i = 0; i < V_S.size(); i++) {
            auto p = V_S[i];
            auto q = V_T[i];
            if (p.first != q.first) {
                cout << "No" << endl;
                return 0;
            } else if (p.second > q.second) {
                cout << "No" << endl;
                return 0;
            } else if (p.second != q.second && p.second == 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
