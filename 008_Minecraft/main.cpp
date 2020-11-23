#include <iostream>

/*
 * Нам всё-таки предстоит сделать некое подобие Майнкрафта.
 * Миллионов не обещаю, но это довольно интересная задача на пространственное мышление.
 * У нас есть небольшой квадратный ландшафт, размером 5х5 секторов.
 * В каждом секторе располагается блок (столбик) ландшафта, максимальная высота которого - это 10 блоков.
 * Текущая высота каждого такого блока задаётся пользователем вначале программы.
 * Итоговая задача - используя трёхмерный массив вывести в стандартный вывод горизонтальное сечение
 *  (или горизонтальный срез) нашего небольшого мира.
 * Сам мир как раз должен быть представлен в виде трёхмерного массива.
 * Его горизонтальный срез стало быть - это двумерный массив, который надо отобразить в виде единиц и нулей.
 * 0 - это отсутствие элемента на данном уровне в данной точке, 1 - элемент есть.
 * Уровень среза от 0 до 9 включительно - также задаётся в стандартном вводе.
 */

char InitSquare(char arr[5][5][10]) {
    int b;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << "Input the height (from 1 to 10):";
            std::cin >> b;
            while (b < 1 || b > 10) {
                std::cout << "Not correct value. Try again:";
                std::cin >> b;
            }
            for (int k = 0; k < b; k++) {
                arr[i][j][k] = '1';
            }
        }
    }
    return arr[5][5][10];
}

void PrintLevel(char arr[5][5][10], int a) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j][a] == '1') {
                std::cout << arr[i][j][a];
            } else {
                std::cout << '0';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int level;
    char square[5][5][10];

    std::cout << "Input level number to print:";
    std::cin >> level;
    while (level < 0 || level > 9) {
        std::cout << "Wrong level number. Try again:";
        std::cin >> level;
    }

    InitSquare(square);
    std::cout << std::endl;
    std::cout << "Result:" << std::endl;
    PrintLevel(square, level);
}
