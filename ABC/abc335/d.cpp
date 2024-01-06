#include <bits/stdc++.h>
using namespace std;

int N;
bool is_in(int x, int y) {return 0 <= x && x < N && 0 <= y && y < N;}
vector<int> dy{1, 0, -1, 0}, dx{0, 1, 0, -1};

int main() {
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, 0));

    int x = 0, y = 0, k = 0;
    for (int n = 1; n <= N*N-1; n++) {
        A[x][y] = n;
        while (!is_in(x+dx[k], y+dy[k]) || A[x+dx[k]][y+dy[k]] != 0) k = (k+1) % 4;
        x = x + dx[k];
        y = y + dy[k];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != 0) cout << A[i][j] << " ";
            else cout << "T" << " ";
        }
        cout << "\n";
    }
}
