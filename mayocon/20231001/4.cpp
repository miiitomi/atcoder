// https://atcoder.jp/contests/abc064/tasks/abc064_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    deque<char> D;

    for (char c : S) {
        if (D.empty() || c == '(' || D.back() == ')') {
            D.push_back(c);
        } else {
            D.pop_back();
        }
    }

    int a=0, b=0;
    while (!D.empty() && D.front() == ')') {
        a++;
        D.pop_front();
    }
    while (!D.empty() && D.back() == '(') {
        b++;
        D.pop_back();
    }

    for (int i = 0; i < a; i++) cout << '(';
    cout << S;
    for (int j = 0; j < b; j++) cout << ')';
    cout << endl;
}
