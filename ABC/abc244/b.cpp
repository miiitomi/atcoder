#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};

int main() {
    int N;
    cin >> N;
    string T;
    cin >> T;
    int x = 0;
    int y = 0;
    int now = 0;
    for (int i = 0; i < N; i++) {
        if (T[i] == 'S') {
            x += dx[now];
            y += dy[now];
        } else {
            now = (now + 1) % 4;
        }
    }
    cout << x << " " << y << endl;
}
