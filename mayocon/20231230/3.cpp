// https://atcoder.jp/contests/abc243/tasks/abc243_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), v;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    string S;
    cin >> S;

    vector<vector<int>> L(v.size()), R(v.size());

    for (int i = 0; i < N; i++) {
        x[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), x[i]));
        y[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), y[i]));
        if (S[i] == 'L') {
            L[y[i]].push_back(x[i]);
        } else {
            R[y[i]].push_back(x[i]);
        }
    }

    for (int k = 0; k < v.size(); k++) {
        if (L[k].empty() || R[k].empty()) continue;
        sort(L[k].begin(), L[k].end());
        sort(R[k].begin(), R[k].end());
        if (R[k][0] < L[k].back()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
