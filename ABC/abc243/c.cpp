#include <bits/stdc++.h>
using namespace std;

bool f(vector<pair<int, char>> V) {
    sort(V.begin(), V.end());
    int right_first = -1;
    for (int i = 0; i < (int)V.size(); i++) {
        if (V[i].second == 'R') {
            right_first = i;
            break;
        }
    }
    if (right_first == -1) return false;

    int left_first = -1;
    for (int i = (int)V.size()-1; i >= 0; i--) {
        if (V[i].second == 'L') {
            left_first = i;
            break;
        }
    }
    if (left_first == -1) return false;

    return (right_first < left_first);
}

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    string S;
    cin >> S;

    map<int, vector<pair<int, char>>> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        x = X[i];
        y = Y[i];
        char c = S[i];
        if (M.count(y)) {
            M[y].push_back(make_pair(x, c));
        } else {
            M[y] = {};
            M[y].push_back(make_pair(x, c));
        }
    }

    for (auto p : M) {
        if (f(p.second)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
