// https://atcoder.jp/contests/abc273/tasks/abc273_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    vector<pair<int, int>> V;
    V.reserve(Q);
    V.push_back(make_pair(-1, 0));
    int now = 0;
    map<int, int> M;

    for (int q = 0; q < Q; q++) {
        string s;
        int x;
        cin >> s;
        if (s != "DELETE") cin >> x;

        if (s == "DELETE") {
            if (now != 0) now = V[now].second;
        }
        if (s == "ADD") {
            V.push_back(make_pair(x, now));
            now = (int)V.size() - 1;
        }
        if (s == "SAVE") {
            M[x] = now;
        }
        if (s == "LOAD") {
            if (M.count(x)) now = M[x];
            else now = 0;
        }
        cout << V[now].first << " ";
    }
    cout << endl;
}
