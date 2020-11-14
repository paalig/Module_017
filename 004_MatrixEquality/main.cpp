#include <iostream>
/*
 * Требуется реализовать небольшую программу для сравнения двух двумерных матриц размерами 4х4
 *  на предмет их полного равенства.
 * Программа принимает на вход две целочисленные матрицы A и B, которые вводятся с помощью std::cin
 *  и сравнивает их на предмет полного равенства. Если матрицы равны, то об этом сообщается в стандартном выводе.
 *  Алгоритм должен быть по возможности оптимальным и не проводить лишних операций.
 */

int inputMatrix(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Input value: ";
            std::cin >> arr[i][j];
        }
    }
    return arr[4][4];
}

int main() {
    int arr1[4][4];
    int arr2[4][4];

    std::cout << "First matrix input" << std::endl;
    std::cout << std::endl;
    inputMatrix(arr1);
    std::cout << std::endl;

    std::cout << "Second matrix input" << std::endl;
    std::cout << std::endl;
    inputMatrix(arr2);
    std::cout << std::endl;

    bool check = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr1[i][j] != arr2[i][j]) {
                check = false;
                break;
            }
        }
        if (!check) {break;}
    }
    if (check) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not equal" << std::endl;
    }
}
