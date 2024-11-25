#include <iostream>

// 13
void contextMenu();
double DoubleInput();
bool RestartProgramm();
int ArraySizeInput();

int main()
{
  contextMenu();
  bool restartFlag = RestartProgramm();

  while (restartFlag)
  {
    double sum = 0;
    double multiple = 1;

    const int n = ArraySizeInput();
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i)
    {
      matrix[i] = new double[n];
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        std::cout << "Введите элемент массива " << "[" << i << "] [" << j << "]: ";
        matrix[i][j] = DoubleInput();
        if (i <= j && i + j <= n-1 || i >= j && i + j >= n-1)
        {
          sum += matrix[i][j];
          multiple *= matrix[i][j];
        }
      }
    }

    std::cout << "Ввёденная матрица:\n";
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << '\n';
    }

    std::cout << '\n' << "Произведение: " << multiple << '\n';
    std::cout << "Сумма: " << sum << '\n';

    for (int i = 0; i < n; ++i)
    {
      delete[] matrix[i];
      matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;

    restartFlag = RestartProgramm();
  }
  return 0;
}

void contextMenu()
{
  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "Вводится динамически квадратная матрица порядка n. Выводится сумма и произведение элементов (обозначенные нулями).\n";
  std::cout << "0 0 0 0 0\n" <<
               "  0 0 0  \n" <<
               "    0    \n" <<
               "  0 0 0  \n" <<
               "0 0 0 0 0\n";
  std::cout << "Вариант 13\n";
  std::cout << "----------------------------------------------------------------------------------------------------\n";
}

bool RestartProgramm()
{
	std::cout << "\nВведите 0, чтобы завершить программу\n        1, чтобы запустить программу\n";
	bool a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

double DoubleInput()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

int ArraySizeInput()
{
	int a;
  std::cout << "Введите порядок квадратной матрицы: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}