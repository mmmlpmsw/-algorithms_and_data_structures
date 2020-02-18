//
// Created by mmmlpmsw on 10.02.2020.
//


#include <iostream>
#include <bits/stdc++.h>

// 1296. Гиперпереход
using namespace std;

int main() {

    int n;
    cin >> n;
    int p[n];

    int supposedAnswer[n];

    int answer = 0; //даже для худшего случая это так, меньше уже точно некуда

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        answer += p[i];
        if (answer < 0)
            answer = 0;
        supposedAnswer[i] = answer;
    }
    answer = 0;
    for (int i = 0; i < n; i ++) {
        if (supposedAnswer[i] > answer)
            answer = supposedAnswer[i];
    }
    cout << answer << endl;
    return 0;
}
//Время работы – O(n)
