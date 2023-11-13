#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int d;
        cin >> d;
        int x = i % 10;
        int y = i / 10;
        for (int s = 1; s <= d; s++) {
            int a = s % 10;
            int b = s / 10;
            if (s <= 9) {
                if ((s == i) || ((s == x) && (s == y))) cnt++;
            } else {
                if (a == b) {
                    if ((a == i) || (a == x && a == y)) cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}
