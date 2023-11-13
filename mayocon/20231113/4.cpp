// https://atcoder.jp/contests/abc110/tasks/abc110_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();

    vector<vector<bool>> v(26, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        int x = S[i] - 'a';
        v[x][i] = true;
    }

    map<int, int> mp;
    for (int i = 0; i < 26; i++) mp[i] = i;

    for (int i = 0; i < N; i++) {
        int x;
        for (int j = 0; j < 26; j++) {
            if (v[mp[j]][i]) {
                x = j;
                break;
            }
        }
        int y = T[i] - 'a';
        if (x != y) swap(mp[x], mp[y]);
    }

    for (int i = 0; i < N; i++) {
        int x;
        for (int j = 0; j < 26; j++) {
            if (v[mp[j]][i]) {
                x = j;
                break;
            }
        }
        int y = T[i] - 'a';
        if (x != y) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
