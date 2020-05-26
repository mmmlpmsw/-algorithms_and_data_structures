#include <iostream>
#include <vector>

// Алгоритм Беллмана-Форда.

struct pipe {
    int a, b, c;
};

std::vector<pipe> pipes;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> res(510, -1);

    for (int i = 0; i < m; i ++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        pipes.push_back({a - 1, b - 1, c});
    }
    int s, f;
    std::cin >> s >> f;
    s--;
    f--;

    res[s] = 0;

    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < m; j++) {
            if (res[pipes[j].a] != -1 && res[pipes[j].b] < res[pipes[j].a] + pipes[j].c) {
                res[pipes[j].b] = res[pipes[j].a] + pipes[j].c;
            }
        }
    }

    if (res[f] != -1) {
        std::cout << res[f];
    } else {
        std::cout << "No solution";
    }

    return 0;
}
