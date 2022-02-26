#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> x;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        x[a]++;
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        if (!x.count(b) || x[b] == 0) {
            cout << "No" << endl;
            return 0;
        }
        x[b]--;
    }
    cout << "Yes" << endl;
}
