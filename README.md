# Nesh
Homework #2  [![Build Status](https://travis-ci.org/KostinaElizaveta/Nesh.svg?branch=master)](https://travis-ci.org/KostinaElizaveta/Nesh)


Проект Nesh создан для исследования биматричных игр на устойчивость по Нэшу и оптимальность по Парето.
Входные данные задаются в виде матрицы и введены в коде программы,на консоли пользователь может выбрать один из 5 пунктов: 
1) дилемма заключенного;
2) семейный спор;
3) перекресток;
4) случайная матрица;
5) выход из программы.
В первых трех случаях рассматриваются известные дилеммы, в четвертом пункте пользователь может сам ввести данные с клавиатуры в консоли.

Программа получает на вход значения матрицы.


Класс matrix состоит из:
1) void init()-Инициализация игровой матрицы;
2) void init_i()-Инициализация известной игры;
3) void zakl()-Инициализация дилеммы заключенного;
4) void spor()-Инициализация семейного спора;
5) void perekrestok()-Инициализация перекрестка;
6) bool nash(int** &A, int** &B, int x, int y)-Оптимальные стратегии по Нэшу;
7) bool pareto(int** &A, int** &B, int x, int y)-Оптимальные стратегии по Парето;
8) void random()-Заполнение матрицы случайными числами;
9) void clear()-Очистка памяти;
10)void print()-Вывод матрицы;
11)void check()-Проверка;

Тестирование проекта осуществлялось вручную для каждого случая, наборы переменных содержатся в папке /tests.
