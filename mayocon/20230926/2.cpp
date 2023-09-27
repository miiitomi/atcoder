// https://atcoder.jp/contests/abc237/tasks/abc237_c
#include <bits/stdc++.h>
using namespace std;

bool kaibun(string T) {
    string U = T;
    reverse(U.begin(), U.end());

    if (T == U) return true;
    else return false;
}

int main() {
    string S;
    cin >> S;
    int N = S.size();

    int i = 0;
    while (i < N && S[i] == 'a') i++;

    if (i == N) {
        cout << "Yes" << endl;
        return 0;
    }

    int j = 0;
    while (j < N && S[N-1-j] == 'a') j++;

    if (i  > j) {
        cout << "No" << endl;
        return 0;
    }

    string T = "";
    T.reserve(N);
    for (int k = i; k <= N-1-j; k++) T.push_back(S[k]);

    if (kaibun(T)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
