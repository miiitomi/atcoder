// https://atcoder.jp/contests/abc218/tasks/abc218_c
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> S) {
    vector<vector<int>> V(S[0].size(), vector<int>(S.size(), 0));
    for (int i = 0; i < (int)S.size(); i++) {
        for (int j = 0; j < (int)S[0].size(); j++) {
            V[j][V[0].size()-1-i] = S[i][j];
        }
    }
    return V;
}

vector<vector<int>> trans(vector<vector<int>> S) {
    while (S.back() == vector<int>(S[0].size(), 0)) S.pop_back();
    while (S.front() == vector<int>(S[0].size(), 0)) S.erase(S.begin());
    do {
        bool can_erase = true;
        for (int i = 0; i < (int)S.size(); i++) if (S[i].back() != 0) can_erase = false;
        if (!can_erase) break;
        for (int i = 0; i < (int)S.size(); i++) S[i].pop_back();
    } while(true);
    do {
        bool can_erase = true;
        for (int i = 0; i < (int)S.size(); i++) if (S[i].front() != 0) can_erase = false;
        if (!can_erase) break;
        for (int i = 0; i < (int)S.size(); i++) S[i].erase(S[i].begin());
    } while(true);
    return S;
}

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N, 0)), T(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') S[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') T[i][j] = 1;
        }
    }

    S = trans(S);
    T = trans(T);



    for (int k = 0; k < 4; k++) {
        if (S == T) {
            cout << "Yes\n";
            return;
        }
        S = rotate(S);
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
