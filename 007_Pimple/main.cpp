#include <iostream>
#include <cmath>

/*
 * После посылки из Китая осталась спец. плёнка для бережной перевозки груза - пупырка.
 * Всего в пупырке 12 на 12 шариков-пузырьков.
 * Состояние любого пузырька - это всегда либо он целый - либо нет, т.е. true или false (тип массива bool).
 * Для начала, требуется реализовать отдельную функцию инициализации пупырки начальным состоянием
 *  - полностью целая пупырка, т.е. все элементы true. Но это только самое начало.
 *
 * Программа заключается в последовательном лопанье целых регионов пузырьков.
 * Перед каждым таким лопаньем надо показывать пользователю полностью всю плёнку: o - это целый пузырёк, x - лопнутый.
 * Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопанье.
 * Пользователь вводит две координаты: координаты начала региона и конца региона.
 * Сама процедура лопанья пузырей должна быть реализована с помощью отдельной функции,
 *  все аргументы должны проверяться на их валидность, что они в в рамках диапазона возможных значений
 *  - иначе должна быть выведена ошибка.
 * После лопанья каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.
 * 
 * Лопанье должно продолжаться до последнего пузырька.
 * Как только вся пупырка потрачена, программа заканчивает выполнение.
 * В принципе, вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки,
 *  т.к. она выполняется после каждого лопанья.
 */
int init(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            arr[i][j] = true;
        }
    }
    return arr[12][12];
}

void printPimple(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j]) {
                std::cout << "o";
            } else {
                std::cout << "x";
            }
        }
        std::cout << std::endl;
    }
}

int action(bool arr[12][12], int a, int b, int c, int d) {
    for (int i = std::min(a, c); i <= std::max(a, c); i++) {
        for (int j = std::min(b, d); j <= std::max(b, d); j++) {
            if (arr[i][j]) {
                arr[i][j] = false;
                std::cout << "Pop!" << std::endl;
            }
        }
    }
    return arr[12][12];
}

bool checkPimple(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    bool pimple[12][12];
    init(pimple);
    printPimple(pimple);
    int a, b, c, d;

    while (checkPimple(pimple)) {
        std::cout << "Input start coordinates: ";
        std::cin >> a >> b;
        std::cout << "Input end coordinates: ";
        std::cin >> c >> d;
        while (a > 11 || b > 11 || c > 11 || d > 11 ||
               a < 0 || b < 0 || c < 0 || d < 0) {
            std::cout << "Invalid values. Try again!" << std::endl;
            std::cout << "Input start coordinates: ";
            std::cin >> a >> b;
            std::cout << "Input end coordinates: ";
            std::cin >> c >> d;
        }
        action(pimple, a, b, c, d);
        printPimple(pimple);
        std::cout << std::endl;
    }
    std::cout << "Game is finished!";
}
