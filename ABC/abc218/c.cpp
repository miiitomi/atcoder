#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S, T;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        T.push_back(s);
    }

    while (true) {
        bool empty = true;
        for (int j = 0; j < N; j++) {
            if (S[0][j] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) S.erase(S.begin());
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < N; j++) {
            if (S[(int)S.size()-1][j] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) S.erase(S.end()-1);
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < (int)S.size(); j++) {
            if (S[j][0] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) {
            for (int j = 0; j < (int)S.size(); j++) S[j].erase(S[j].begin()); 
        }
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < (int)S.size(); j++) {
            if (S[j][(int)S[j].size()-1] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) {
            for (int j = 0; j < (int)S.size(); j++) S[j].erase(S[j].end()-1); 
        }
        else break;
    }

    while (true) {
        bool empty = true;
        for (int j = 0; j < N; j++) {
            if (T[0][j] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) T.erase(T.begin());
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < N; j++) {
            if (T[(int)T.size()-1][j] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) T.erase(T.end()-1);
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < (int)T.size(); j++) {
            if (T[j][0] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) {
            for (int j = 0; j < (int)T.size(); j++) T[j].erase(T[j].begin()); 
        }
        else break;
    }
    while (true) {
        bool empty = true;
        for (int j = 0; j < (int)T.size(); j++) {
            if (T[j][(int)T[j].size()-1] == '#') {
                empty = false;
                break;
            }
        }
        if (empty) {
            for (int j = 0; j < (int)T.size(); j++) T[j].erase(T[j].end()-1); 
        }
        else break;
    }

    int count = 0;
    while (true) {
        count++;
        if (count == 5) break;
    
        vector<string> S_old;
        for (int i = 0; i < (int)S.size(); i++) S_old.push_back(S[i]);
        S.resize(0);
        for (int i = 0; i < (int)S_old[0].size(); i++) {
            string s;
            for (int j = (int)S_old.size()-1; j >= 0; j--) {
                s = s + S_old[j][i];
            }
            S.push_back(s);
        }

        if ((int)S.size() != (int)T.size() || (int)S[0].size() != (int)T[0].size()) continue;

        bool ans = true;
        for (int k = 0; k < (int)S.size(); k++) {
            for (int l = 0; l < (int)S[0].size(); l++) {
                if (S[k][l] != T[k][l]) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
        if (ans) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
