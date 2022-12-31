#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(1501, vector<int>(1501, 0));

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A[x][y]++;
    }

    for (int h = 1; h < 1501; h++) {
        for (int w = 1; w < 1501; w++) A[h][w] = A[h][w] + A[h][w-1];
    }

    for (int w = 1; w < 1501; w++) {
        for (int h = 1; h < 1501; h++) {
            A[h][w] = A[h][w] + A[h-1][w];
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int w, x, y, z;
        w = min(a, c);
        y = max(a, c);
        x = min(b, d);
        z = max(b, d);
        cout << A[y][z] - A[y][x-1] - A[w-1][z] + A[w-1][x-1] << endl;
    }
}
