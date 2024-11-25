#include <iostream>

// 13
void contextMenu();
int IntInput();
bool RestartProgramm();
int ArrayRowsInput();
int ArrayColumnsInput();

int main()
{
  contextMenu();
  bool restartFlag = RestartProgramm();

  while (restartFlag)
  {
    const int m = ArrayRowsInput(); 
    const int n = ArrayColumnsInput();
    int matrix[m][n];
    int result = 0;
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        std::cout << "Введите элемент массива " << "[" << i << "] [" << j << "]: ";
        matrix[i][j] = IntInput();
        if (i % 2 == 1)
        {
          result += matrix[i][j];
        }
      }
    }

    std::cout << "Сумма в четных строках равна: " << result << '\n';
    restartFlag = RestartProgramm();
  }
  return 0;
}

void contextMenu()
{
  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "Вводится статический двумерный массив размером m x n. Выводится сумма элементов из четных строк матрицы.\n";
  std::cout << "Вариант 13\n";
  std::cout << "----------------------------------------------------------------------------------------------------\n";
}

bool RestartProgramm()
{
	std::cout << "Введите 0, чтобы завершить программу\n        1, чтобы запустить программу\n";
	bool a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

int IntInput()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

int ArrayRowsInput()
{
	int a;
  std::cout << "Введите количество строчек массива: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}

int ArrayColumnsInput()
{
	int a;
  std::cout << "Введите количество столбцов массива: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}