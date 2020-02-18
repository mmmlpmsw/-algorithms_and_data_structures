//
// Created by mmmlpmsw on 10.02.2020.
//

#include <iostream>
#include <bits/stdc++.h>

//1005. Куча камней

using namespace std;
void divide (int sum1, int sum2, int iterator, int arr[]);
int ans = 100001;
int n;

int main() {

    cin >> n;
    int w[n];
    for (int i = 0; i < n; i ++) {
        cin >> w[i];
    }

    divide(0, 0, 0, w);
    cout << ans << endl;

    return 0;
}

void divide (int sum1, int sum2, int iterator, int arr[]) {
    if (iterator == n) {
        ans = min(ans, abs(sum1 - sum2));
    }
    else {
        divide(sum1 + arr[iterator], sum2, iterator + 1, arr);
        divide(sum1, sum2 + arr[iterator], iterator + 1, arr);
    }

}

//Оценка времени работы – 2^n
