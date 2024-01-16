// https://atcoder.jp/contests/abc237/tasks/abc237_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> A;
    A.push_back(0);
    string S;
    cin >> S;

    int s = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            if (s == i) s = i+1;
            A.pop_back();
            A.push_back(i+1);
            A.push_front(i);
        } else {
            A.push_back(i+1);
        }
    }

    while (A[0] != s) {
        A.push_back(A.front());
        A.pop_front();
    }

    for (int a : A) cout << a << " ";
    cout << endl;
}
