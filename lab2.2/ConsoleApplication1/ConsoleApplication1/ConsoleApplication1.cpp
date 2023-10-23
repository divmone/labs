// number13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Russian");
    long long** p = NULL;
    std::cout << "Выполнил задание Суровцев Артём 353505. \nНеобходимо ввести с клавиатуры n - размер  массива n*n. Затем, в следующей строке ввести массив из n^2 вещественных чисел. Требуется построить магический квадрат.\n";
    std::cout << "Введите одно натуральное число не больше (2^32 - 1) - количество строк в массиве (если вы введёте более одного удовлетворяющего числа, размером массива будет считаться первое):\n";
    long double n;
    while (true) {
        if ((std::cin >> n).good() && (long long)n == n && n < 4294967293) break; //если введено ЦЕЛОЕ ЧИСЛО меньше 2^32 - 3
        else {
            std::cin.clear(); // очищаем поток
            std::cout << "Неверный ввод. Пожалуйста, введите одно целое число не больше 2^32 - 3 - количество элементов в массиве:\n";
            std::cin.sync(); // убираем все непрочитанные символы из входного потока
        }
    }
    std::cin.sync();
    long long normal_n = (long long)n;
    p = (long long**)malloc(normal_n * sizeof(long long*));
    for (int i = 0; i < normal_n; i++) {
        p[i] = (long long*)malloc(normal_n * sizeof(long long));
    }

    for (int i = 0; i < normal_n; ++i) {
        for (int j = 0; j < normal_n; ++j) {
            p[i][j] = 0;
        }
    }

    if (normal_n % 2 != 0) {
        long long i = 0, j = normal_n / 2, cnt = 1;
        while (cnt != normal_n * normal_n + 1) {
            while (p[i][j] == 0 && cnt != normal_n * normal_n + 1) {
                p[i][j] = cnt;
                cnt++;
                if (i == 0 && j < normal_n - 1) {
                    ++j;
                    i = normal_n - 1;
                }
                else if (j == normal_n - 1 && i > 0) {
                    --i;
                    j = 0;
                }
                else if (j == normal_n - 1 && i == 0) {
                    i++;
                }
                else {
                    --i;
                    ++j;
                }
            }
            i += 2;
            --j;
        }
    }
    else if (normal_n % 4 == 0) {
        long long cnt = 1;
        for (int i = 0; i < normal_n; ++i) {
            for (int j = 0; j < normal_n; ++j) {
                p[i][j] = cnt;
                cnt++;
            }
        }
        cnt = 1;
        for (int i = 0; i < normal_n; ++i) {
            for (int j = 0; j < normal_n; ++j) {
                if (!((i < n / 4 || i > n - 1 - n / 4) && (j < n / 4 || j > n - 1 - n / 4)) || (i >= n / 4 && i <= n - 1 - n / 4 && j >= n / 4 && j <= n - 1 - n / 4)) {
                    p[i][j] = normal_n * normal_n - cnt + 1;
                    cnt++;
                }
                else cnt++;
            }
        }
    }
    else {
        long long cnt = 1;
        while (cnt != normal_n * normal_n + 1) {
            long long i = 0, j = normal_n / 4;
            while (cnt != (normal_n / 2) * (normal_n / 2) + 1) {
                while (p[i][j] == 0 && cnt != (normal_n / 2) * (normal_n / 2) + 1) {
                    p[i][j] = cnt;
                    cnt++;
                    if (i == 0 && j < normal_n / 2 - 1) {
                        ++j;
                        i = normal_n / 2 - 1;
                    }
                    else if (j == normal_n / 2 - 1 && i > 0) {
                        --i;
                        j = 0;
                    }
                    else if (j == normal_n / 2 - 1 && i == 0) {
                        i++;
                    }
                    else {
                        --i;
                        ++j;
                    }
                }
                i += 2;
                --j;
            }
            i = normal_n / 2, j = normal_n / 2 + normal_n / 4;
            while (cnt != 2 * (normal_n / 2) * (normal_n / 2) + 1) {
                while (p[i][j] == 0 && cnt != 2 * (normal_n / 2) * (normal_n / 2) + 1) {
                    p[i][j] = cnt;
                    cnt++;
                    if (i == normal_n / 2 && j < normal_n - 1) {
                        ++j;
                        i = normal_n - 1;
                    }
                    else if (j == normal_n - 1 && i > normal_n / 2) {
                        --i;
                        j = normal_n / 2;
                    }
                    else if (j == normal_n - 1 && i == normal_n / 2) {
                        i++;
                    }
                    else {
                        --i;
                        ++j;
                    }
                }
                i += 2;
                --j;
            }
            i = 0, j = normal_n / 2 + normal_n / 4;
            while (cnt != 3 * (normal_n / 2) * (normal_n / 2) + 1) {
                while (p[i][j] == 0 && cnt != 3 * (normal_n / 2) * (normal_n / 2) + 1) {
                    p[i][j] = cnt;
                    cnt++;
                    if (i == 0 && j < normal_n - 1) {
                        ++j;
                        i = normal_n / 2 - 1;
                    }
                    else if (j == normal_n - 1 && i > 0) {
                        --i;
                        j = normal_n / 2;
                    }
                    else if (j == normal_n - 1 && i == 0) {
                        i++;
                    }
                    else {
                        --i;
                        ++j;
                    }
                }
                i += 2;
                --j;
            }
            i = normal_n / 2, j = normal_n / 4;
            while (cnt != normal_n * normal_n + 1) {
                while (p[i][j] == 0 && cnt != normal_n * normal_n + 1) {
                    p[i][j] = cnt;
                    cnt++;
                    if (i == normal_n / 2 && j < normal_n / 2 - 1) {
                        ++j;
                        i = normal_n - 1;
                    }
                    else if (j == normal_n / 2 - 1 && i > normal_n / 2) {
                        --i;
                        j = 0;
                    }
                    else if (j == normal_n / 2 - 1 && i == normal_n / 2) {
                        i++;
                    }
                    else {
                        --i;
                        ++j;
                    }
                }
                i += 2;
                --j;
            }
        }
        for (int i = 0; i < normal_n / 2; i++) {
            for (int j = 0; j < normal_n / 4; j++) {
                if (i == normal_n / 4) {
                    long long temp = p[i][j + 1];
                    p[i][j + 1] = p[i + normal_n / 2][j + 1];
                    p[i + normal_n / 2][j + 1] = temp;
                }
                else {
                    long long temp = p[i][j];
                    p[i][j] = p[i + (normal_n / 2)][j];
                    p[i + normal_n / 2][j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < normal_n; ++i) {
        for (int j = 0; j < normal_n; j++) {

            std::cout << p[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < normal_n; i++) {
        free(p[i]);
        p[i] = NULL;
    }
    free(p);
    p = NULL;
    return 0;
}