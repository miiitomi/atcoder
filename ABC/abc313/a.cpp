#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    int x = 0;
    for (int i = 1; i < N; i++) {
        while (P[0]+x <= P[i]) x++;
    }
    cout << x << endl;
}
