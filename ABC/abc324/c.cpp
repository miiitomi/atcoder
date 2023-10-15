#include <bits/stdc++.h>
using namespace std;

bool same(string &S, string &T) {
    int cnt = 0;
    for (int i = 0; i < (int)T.size(); i++) {
        if (S[i] != T[i]) {
            cnt++;
            if (cnt >= 2) return false;
        }
    }
    return true;
}

bool lower(string &S, string &T) {
    int i=0, j=0, cnt=0;
    while (j < (int)T.size()) {
        if (S[i] != T[j]) {
            cnt++;
            if (cnt >= 2) {
                return false;
            }
            j++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

bool larger(string &S, string &T) {
    int i=0, j=0, cnt=0;
    while (i < (int)T.size()+1) {
        if (S[i] != T[j]) {
            cnt++;
            if (cnt >= 2) {
                return false;
            }
            i++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<int> ans;
    ans.reserve(N);

    for (int t = 1; t <= N; t++) {
        string S;
        cin >> S;

        if ((int)S.size() == (int)T.size()) {
            if (same(S, T)) ans.push_back(t);
        } else if ((int)S.size() == (int)T.size() - 1) {
            if (lower(S, T))  ans.push_back(t);
        } else if ((int)S.size() == (int)T.size() + 1) {
            if (larger(S, T)) ans.push_back(t);
        }
    }

    cout << (int)ans.size() << endl;
    for (int a : ans) cout << a << " ";
    cout << endl;
}
