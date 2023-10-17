// https://atcoder.jp/contests/abc320/tasks/abc320_b
#include <bits/stdc++.h>
using namespace std;

string S;

int is_kaibun(int i, int j) {
    for (int k = 0; k + i <= j; k++) {
        if (S[i+k] != S[j-k]) return -1;
    }
    return j - i + 1;
}

int main() {
    cin >> S;
    int tmp = -1;
    for (int i = 0; i < (int)S.size(); i++) {
        for (int j = i; j < (int)S.size(); j++) {
            tmp = max(tmp, is_kaibun(i, j));
        }
    }
    cout << tmp << endl;
}
