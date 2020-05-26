#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int colors[100];
vector<int> region[100];
int n;

void detour(int st) {
    queue<int> queue;
    queue.push(st);
    colors[st] = 0;

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (int i = 0; i < region[v].size(); ++i) {
            int destination = region[v][i];
            if (colors[v] == colors[destination]) {
                cout << "-1"; //нельзя покрасить в 2 цвета совсем
                exit(0);
            }
            if (colors[destination] == -1) {
                if (colors[v] == 0) {
                    colors[destination] = 1;
                } else {
                    colors[destination] = 0;
                }
                queue.push(destination);
            }
        }
    }
}

int main(){
    cin >> n;

    fill_n(colors, 100, -1);
    for (int i = 0; i < n; ++i) {
        int e = -1;
        while (e != 0) {
            cin >> e;
            if (e != 0) {
                region[e - 1].push_back(i);
                region[i].push_back(e - 1);
            }
        }
    }

    detour(0);

    for(int i = 0; i < n; ++i){
        if(colors[i] == -1) {
            detour(i);
        }
        cout << colors[i];
    }

    return 0;
}
