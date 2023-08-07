#include <bits/stdc++.h>
using namespace std;

void round(vector<int> &A, int k, int &m) {
    if (A[k] >= 5) {
        A[k+1]++;
        m = k;
    }
}

void solve() {
    string S;
    cin >> S;
    vector<int> A((int)S.size()+1, 0);
    for (int i = (int)S.size()-1; i>=0; i--) {
        A[(int)S.size()-1-i] = (int)S[i] - (int)'0';
    }
    int m = -1;
    for (int i = 0; i < (int)S.size(); i++) round(A, i, m);
    for (int i = 0; i <= m; i++) A[i] = 0;
    for (int i = (int)A.size()-1; i >= 0; i--) {
        if (i == (int)A.size()-1) {
            if (A[i] > 0) cout << A[i];
        } else {
            cout << A[i];
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
