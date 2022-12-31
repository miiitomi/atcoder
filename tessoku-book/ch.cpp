#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(1502, vector<int>(1502, 0));

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[a][b]++;
        A[a][d]--;
        A[c][b]--;
        A[c][d]++;
    }
    for (int h = 0; h <= 1500; h++) {
        for (int w = 1; w <= 1500; w++) {
            A[h][w] = A[h][w] + A[h][w-1];
        }
    }
    for (int w = 0; w <= 1500; w++) {
        for (int h = 1; h <= 1500; h++) {
            A[h][w] = A[h][w] + A[h-1][w];
        }
    }

    int ans = 0;

    for (int h = 0; h <= 1500; h++) {
        for (int w = 0; w <= 1500; w++) {
            if (A[h][w] > 0) ans++;
        }
    }

    cout << ans << endl;
}
