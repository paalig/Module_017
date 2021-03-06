#include <iostream>
#include <vector>

/*
 * Реализуйте частный случай умножения матрицы на матрицу, а именно - умножение вектора на матрицу.
 * Данная операция также весьма распространена в компьютерной индустрии в целом и в компьютерное графике в частности,
 *  поэтому это будет хорошим упражнением.
 *
 * Итак, у нас есть 4-х компонентный вектор V представленный с помощью массива, и матрица M размером 4х4,
 *  представленная в виде двумерного массива. Их произведением будет новый 4-х компонентный вектор R.
 * Его компоненты будут суммой произведений компонент вектора V на столбец матрицы M.
 * Индекс столбца при этом равен индексу соответствующей компоненты вектора R,
 *  который мы и рассчитываем в текущий момент времени.
 *
 * Все входные данные, матрица M и вектор V вносятся из пользовательского ввода.
 * Итоговый вектор R надо вывести в консоль. Тип данных элементов - всегда float.
 * Желательно реализовать этот алгоритм с помощью вложенного цикла на умножение колонки.
 */

float inputMatrix(float arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Input value: ";
            std::cin >> arr[i][j];
        }
    }
    return arr[4][4];
}

std::vector<float> inputVector(int a) {
    std::vector<float> v(a);
    for (int i = 0; i < a; i++) {
        std::cout << "Input value: ";
        std::cin >> v[i];
    }
    return v;
}

void printVector(std::vector<float> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << "\t";
    }
}

std::vector<float> multiplyVectorMatrix(std::vector<float> vec, float matrix[4][4]) {
    for (int j = 0; j < vec.size(); j++) {
        float sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += (vec[j] * matrix[i][j]);
        }
        vec[j] = sum;
    }
    return vec;
}

int main() {
    int vectorSize = 4;
    float m[4][4];

    std::cout << "Input vector: " << std::endl;
    std::vector<float> v = inputVector(vectorSize);
    std::cout << std::endl;

    std::cout << "Input matrix: " << std::endl;
    inputMatrix(m);
    std::cout << std::endl;

    v = multiplyVectorMatrix(v, m);
    printVector(v);
}
