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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}