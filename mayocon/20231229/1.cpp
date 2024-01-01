// https://atcoder.jp/contests/abc235/tasks/abc235_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    int tmp = 0;
    while (tmp+1 < N && H[tmp] < H[tmp+1]) tmp++;

    cout << H[tmp] << endl;
}
