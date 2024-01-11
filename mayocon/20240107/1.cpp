// https://atcoder.jp/contests/abc260/tasks/abc260_b
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id, math, english;
    Student(int i, int m, int e): id(i), math(m), english(e) {}
};


int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<int> Math(N, 0), English(N, 0);
    for (int i = 0; i < N; i++) cin >> Math[i];
    for (int i = 0; i < N; i++) cin >> English[i];

    vector<Student> V;
    for (int i = 0; i < N; i++) V.push_back(Student(i+1, Math[i], English[i]));

    vector<int> ans;

    sort(V.begin(), V.end(), [](const Student &s, const Student &t) {if (s.math != t.math) return s.math < t.math; else return s.id > t.id;});
    while (X--) {
        ans.push_back(V.back().id);
        V.pop_back();
    }

    sort(V.begin(), V.end(), [](const Student &s, const Student &t) {if (s.english != t.english) return s.english < t.english; else return s.id > t.id;});
    while (Y--) {
        ans.push_back(V.back().id);
        V.pop_back();
    }

    sort(V.begin(), V.end(), [](const Student &s, const Student &t) {if (s.math + s.english != t.math+t.english) return s.math + s.english < t.math+t.english; else return s.id > t.id;});
    while (Z--) {
        ans.push_back(V.back().id);
        V.pop_back();
    }

    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << endl;
}
