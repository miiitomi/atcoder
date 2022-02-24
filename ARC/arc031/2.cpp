#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<string> &B, int &counter) {
    B[i][j] = 'x';
    counter--;

    if (i > 0 && B[i-1][j] == 'o') dfs(i-1, j, B, counter);
    if (i < 9 && B[i+1][j] == 'o') dfs(i+1, j, B, counter);
    if (j > 0 && B[i][j-1] == 'o') dfs(i, j-1, B, counter);
    if (j < 9 && B[i][j+1] == 'o') dfs(i, j+1, B, counter);
}

int main() {
    vector<string> A(10);
    for (int i = 0; i < 10; i++) cin >> A[i];

    int riku = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i][j] == 'o') riku++;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            vector<string> B = A;
            int counter = riku;
            if (B[i][j] == 'x') counter++;
            B[i][j] = 'o';
            dfs(i, j, B, counter);
            if (counter == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}
