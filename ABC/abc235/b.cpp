#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    int i = 0;
    while (i < N-1) {
        if (H[i] < H[i+1]) {
            i++;
        } else {
            break;
        }
    }
    cout << H[i] << endl;
}
