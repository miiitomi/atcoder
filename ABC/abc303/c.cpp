#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;

    set<pair<int, int> > I;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        I.insert(make_pair(a, b));
    }

    int tairyoku = H;
    int count = 0;
    int x = 0;
    int y = 0;

    while (count < N) {
        char s = S[count];
        if (s == 'R') x++;
        else if (s == 'L') x--;
        else if (s == 'U') y++;
        else if (s == 'D') y--;

        count++;
        tairyoku--;

        if (tairyoku < 0) break;

        if (tairyoku < K && I.count(make_pair(x, y))) {
            tairyoku = K;
            I.erase(make_pair(x, y));
        }
    }

    if (tairyoku >= 0 && count == N) cout << "Yes" << endl;
    else cout << "No" << endl;
}
