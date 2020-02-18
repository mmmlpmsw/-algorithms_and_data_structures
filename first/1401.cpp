//
// Created by mashina.katherina on 10.02.2020.
//

#include <iostream>
#include <cmath>

int arr[512][512];

// i, j - координаты начала квадрата
// x, y - координаты дырки
// n - координаты дырки
void gen(int x, int y, int i, int j, int n) {
    // счетчик для фигур
    static int c;
    c++;
    //если дырка находится в 4 четверти
    if ((x - j) < n / 2 && (y - i) < n / 2) {
        // если мы пришли к задаче 2х2, следует сразу замостить и выйти
        if (n == 2) {
            arr[i][j + 1] = c;
            arr[i + 1][j] = c;
            arr[i + 1][j + 1] = c;
            return;
        }
        // замащиваем фигурой так, чтобы в каждом получившемся
        // квадрате меньшего размера была ровно одна "дырка"
        arr[i + n / 2 - 1][j + n / 2] = c;
        arr[i + n / 2][j + n / 2 - 1] = c;
        arr[i + n / 2][j + n / 2] = c;
        // вызываем функцию для получившихся квадратов, в каждом из которых
        // по одной дырке
        gen(x, y, i, j, n / 2);
        gen(j + n / 2, i + n / 2 - 1, i, j + n / 2, n / 2);
        gen(j + n / 2, i + n / 2, i + n / 2, j + n / 2, n / 2);
        gen(j + n / 2 - 1, i + n / 2, i + n / 2, j, n / 2);

    } //если дырка находится в 1 четверти
    else if ((x - j) >= n / 2 && (y - i) < n / 2) {
        // если мы пришли к задаче 2х2, следует сразу замостить и выйти
        if (n == 2) {
            arr[i][j] = c;
            arr[i + 1][j] = c;
            arr[i + 1][j + 1] = c;
            return;
        }
        // замащиваем фигурой так, чтобы в каждом получившемся
        // квадрате меньшего размера была ровно одна "дырка"
        arr[i + n / 2 - 1][j + n / 2 - 1] = c;
        arr[i + n / 2][j + n / 2 - 1] = c;
        arr[i + n / 2][j + n / 2] = c;
        // вызываем функцию для получившихся квадратов, в каждом из которых по
        // одной  дырке
        gen(j + n / 2 - 1, i + n / 2 - 1, i, j, n / 2);
        gen(x, y, i, j + n / 2, n / 2);
        gen(j + n / 2, i + n / 2, i + n / 2, j + n / 2, n / 2);
        gen(j + n / 2 - 1, i + n / 2, i + n / 2, j, n / 2);
    } //если дырка находится в 2 четверти
    else if ((x - j) >= n / 2 && (y - i) >= n / 2) {
        // если мы пришли к задаче 2х2, следует сразу замостить и выйти
        if (n == 2) {
            arr[i][j] = c;
            arr[i + 1][j] = c;
            arr[i][j + 1] = c;
            return;
        }
        // замащиваем фигурой так, чтобы в каждом получившемся
        // квадрате меньшего размера была ровно одна "дырка"
        arr[i + n / 2 - 1][j + n / 2 - 1] = c;
        arr[i + n / 2][j + n / 2 - 1] = c;
        arr[i + n / 2 - 1][j + n / 2] = c;
        //вызываем функцию для получившихся квадратов, в каждом из которых по
        // одной дырке
        gen(j + n / 2 - 1, i + n / 2 - 1, i, j, n / 2);
        gen(j + n / 2, i + n / 2 - 1, i, j + n / 2, n / 2);
        gen(x, y, i + n / 2, j + n / 2, n / 2);
        gen(j + n / 2 - 1, i + n / 2, i + n / 2, j, n / 2);
    } //если дырка находится в 3 четверти
    else if ((x - j) < n / 2 && (y - i) >= n / 2) {
        // если мы пришли к задаче 2х2, следует сразу замостить и выйти
        if (n == 2) {
            arr[i][j] = c;
            arr[i][j + 1] = c;
            arr[i + 1][j + 1] = c;
            return;
        }
        // замащиваем фигурой так, чтобы в каждом получившемся
        // квадрате меньшего размера была ровно одна "дырка"
        arr[i + n / 2 - 1][j + n / 2 - 1] = c;
        arr[i + n / 2][j + n / 2] = c;
        arr[i + n / 2 - 1][j + n / 2] = c;
        // вызываем функцию для получившихся квадратов, в каждом из которых по
        // одной дырке
        gen(j + n / 2 - 1, i + n / 2 - 1, i, j, n / 2);
        gen(j + n / 2, i + n / 2 - 1, i, j + n / 2, n / 2);
        gen(j + n / 2, i + n / 2, i + n / 2, j + n / 2, n / 2);
        gen(x, y, i + n / 2, j, n / 2);
    }
}

int main() {
    // объявление переменных для хранения характеристики
    // размера поля, а также координат дырки
    int n, x, y;
    // считывание характеристики размера поля и координат дырки
    std::cin >> n >> y >> x;
    // приводим координаты к системе координат с началом в (0;0)
    x--;
    y--;
    // вычисление размера поля
    n = (int) pow(2, n);
    // вызов функции для замощения
    gen(x, y, 0, 0, n);
    // вывод массива результатов
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

