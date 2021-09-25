#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(1000, vector<int>(1000, 0));

    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        A[lx][ly]++;
        if (ry < 1000) A[lx][ry]--;
        if (rx < 1000) {
            A[rx][ly]--;
            if (ry < 1000) A[rx][ry]++;
        }
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            A[i][j] += A[i][j-1];
        }
    }
    for (int j = 0; j < 1000; j++) {
        for (int i = 1; i < 1000; i++) {
            A[i][j] += A[i-1][j];
        }
    }
    vector<int> m(N+1, 0);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            m[A[i][j]]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << m[i] << endl;
    }
}
