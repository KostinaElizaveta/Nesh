                                                           #ifndef _MATRIX_H_
#define _MATRIX_H_
#include <sstream>


class matrix
{
	public:
		void init();//Инициализация игровой матрицы
		void init_i();//Инициализация известной игры
		void zakl();//Инициализация дилеммы заключенного
		void spor();//Инициализация семейного спора
		void perekrestok();//Инициализация перекрестка
		bool nash(int** &A, int** &B, int x, int y);//Оптимальные стратегии по Нэшу
		bool pareto(int** &A, int** &B, int x, int y);//Оптимальные стратегии по Парето
		void random();//Заполнение матрицы случайными числами
		void clear();//Очистка памяти
		void print();//Вывод матрицы
		void check();//Проверка
	private:
		int **A; //Стратегии игрока А
		int **B; //Стратегии игрока В
		int x;//Текущая строка
		int y;//Текущий столбец
		int n;//Число стратегий игрока А
		int m;//Число стратегий игрока В

};
#endif /* _MATRIX_H_ */

