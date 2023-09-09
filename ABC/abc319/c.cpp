#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c(3, vector<int>(3, -1));

bool gakkari(vector<pair<int,int>> &V) {
    vector<vector<int>> d(3, vector<int>(3, -1));
    for (auto v : V) {
        d[v.first][v.second] = c[v.first][v.second];
        
        vector<int> s(10, 0);
        for (int k = 0; k < 3; k++) if (d[v.first][k] != -1) s[d[v.first][k]]++;
        if (*max_element(s.begin(), s.end()) == 2) {
            s[distance(s.begin(), max_element(s.begin(), s.end()))] = 0;
            if (*max_element(s.begin(), s.end()) == 0) return true;
        }

        s.assign(10, 0);
        for (int k = 0; k < 3; k++) if (d[k][v.second] != -1) s[d[k][v.second]]++;
        if (*max_element(s.begin(), s.end()) == 2) {
            s[distance(s.begin(), max_element(s.begin(), s.end()))] = 0;
            if (*max_element(s.begin(), s.end()) == 0) return true;
        }


        if (v.first == v.second) {
            s.assign(10, 0);
            for (int k = 0; k < 3; k++) if (d[k][k] != -1) s[d[k][k]]++;
            if (*max_element(s.begin(), s.end()) == 2) {
                s[distance(s.begin(), max_element(s.begin(), s.end()))] = 0;
                if (*max_element(s.begin(), s.end()) == 0) return true;
            }            
        }

        if (v.first + v.second == 2) {
            s.assign(10, 0);
            for (int k = 0; k < 3; k++) if (d[k][2-k] != -1) s[d[k][2-k]]++;
            if (*max_element(s.begin(), s.end()) == 2) {
                s[distance(s.begin(), max_element(s.begin(), s.end()))] = 0;
                if (*max_element(s.begin(), s.end()) == 0) return true;
            }                  
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> c[i][j];
    }

    vector<pair<int, int>> V;
    V.reserve(9);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) V.push_back(make_pair(i, j));
    }

    int ans = 0;
    do {
        if (!gakkari(V)) ans++;
    } while (next_permutation(V.begin(), V.end()));

    int k = 1;
    for (int i = 1; i <= 9; i++) k *= i;

    cout << fixed << setprecision(15) << (double)ans / (double)k << endl;
}
