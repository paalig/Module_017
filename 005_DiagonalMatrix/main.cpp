#include <iostream>

/*
 * Задание. Для вещественной матрицы M размером 4х4 надо осуществить её преобразование в диагональную.
 * Напомню, что диагональная матрица - это такая матрица, у которой все элементы вне диагонали - равны нулю.
 * Диагональ матрицы, в свою очередь - это все элементы расположенные по диагонали от первого элемента первой строки
 *  до последнего элемента последней строки.
 * Матрица M вводится пользователем через стандартный ввод, как и раньше.
 * Итоговую диагональную матрицу можно расположить на месте прежней матрицы M, не используя дополнительных переменных.
 * Результат требуется вывести в консоль для проверки. Ищите именно оптимальное решение - оно довольно простое.
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

int toDiagonalMatrix(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                arr[i][j] = 0;
            } else {continue;}
        }
    }
    return arr[4][4];
}

void printMatrix(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr1[4][4];

    std::cout << "Input your matrix:" << std::endl;
    std::cout << std::endl;
    inputMatrix(arr1);
    std::cout << std::endl;
    std::cout << "Rebuild to diagonal matrix..." << std::endl;
    toDiagonalMatrix(arr1);
    std::cout << std::endl;
    std::cout << "Result:" << std::endl;
    printMatrix(arr1);

}
