#include <iostream>

// 13
void contextMenu();
int IntInput();
bool RestartProgramm();
int ArraySizeInput();

int main()
{
  contextMenu();
  bool restartFlag = RestartProgramm();

  while (restartFlag)
  {
    int k = ArraySizeInput();
    int arr[k];
    double average = 0;
    for (int i = 0; i < k; ++i)
    {
      std::cout << "Введите " << i << " элемент массива.\n";
      arr[i] = IntInput();
      average += (double(arr[i])/k);
    }

    int counter = 0;
    for (int i = 0; i < k; ++i)
    {
      if (arr[i] - average > 1e-5)
      {
        ++counter;
      }
    }

    std::cout << counter << '\n';

    restartFlag = RestartProgramm();
  }
  return 0;
}

void contextMenu()
{
  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "Вводится статический массив из k чисел, выводится количество элементов, больших чем среднее значение по массиву.\n";
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

int ArraySizeInput()
{
	int a;
  std::cout << "Введите размеры массива: ";
	while (!(std::cin >> a) || (std::cin.peek() != '\n') || a <= 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите попытку:\n";
	}
	return a;
}
