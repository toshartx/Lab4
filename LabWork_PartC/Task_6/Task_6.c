#include <stdio.h>
#include <stdlib.h>

short RestartProgramm();
void ContextMenu();
int ArraySizeInput();
void OddMagicSquare(int **, int);
void DoubleEvenMagicSquare(int **, int);
void SingleEvenMagicSquare(int **, int);

int main()
{
  short restartFlag = RestartProgramm();
  ContextMenu();
  while (restartFlag == 1)
  {
    printf("Введите порядок квадратной матрицы: ");
    int n = ArraySizeInput();

    int **magicSquare = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
      magicSquare[i] = (int *)malloc(n * sizeof(int));
      for (int j = 0; j < n; ++j)
      {
        magicSquare[i][j] = 0;
      }
    }

    int counter = 1;

    // Нечётный квадрат
    if (n % 2 == 1)
    {
      OddMagicSquare(magicSquare, n);
    }
    else if (n % 4 == 0)
    // Чётный квадрат 4n
    {
      DoubleEvenMagicSquare(magicSquare, n);
    }
    else if (n % 4 == 2)
    // Чётный квадрат 4n+2
    {
      SingleEvenMagicSquare(magicSquare, n);
    }

    printf("Ваш магический квадрат:\n");
    for (int i = 0; i < n; ++i)
    {
      printf("\n");
      for (int j = 0; j < n; ++j)
        printf("%4d ", magicSquare[i][j]);
    }

    for (int i = 0; i < n; ++i)
    {
      free(magicSquare[i]);
      magicSquare[i] = NULL;
    }
    free(magicSquare);
    magicSquare = NULL;

    restartFlag = RestartProgramm();
  }
}

int ArraySizeInput()
{
  int a;
  while (!(scanf("%d", &a)) || getchar() != '\n' || a < 3)
  {
    fflush(stdin);
    while (getchar() != '\n')
      ;
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}

void ContextMenu()
{
  printf("----------------------------------------------------------------------------------------------------\n");
  printf("  Вводится порядок квадратной матрицы n. Выводится магический квадрат\n");
  printf("  Магический квадрат - квадратная матрица, в которой сумма по каждому столбцу и строке, а также\n");
  printf("суммы по главной и побочной диагоналях равны числу m = n*(n*n - 1)/2.\n");
  printf(" 8    1    6\n");
  printf(" 3    5    7                 - пример магического квадрата.\n");
  printf(" 4    9    2\n");
  printf("----------------------------------------------------------------------------------------------------\n");
}

short RestartProgramm()
{
  printf("\nВведите 0, чтобы завершить программу\n        1, чтобы запустить программу\n");
  short a;

  while (!(scanf("%hd", &a)) || getchar() != '\n' || a != 0 && a != 1)
  {
    fflush(stdin);
    while (getchar() != '\n');
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}

void OddMagicSquare(int **square, int n)
{
  int counter = 1;
  for (int i = 0, j = n / 2; counter <= n * n;)
  {
    square[i][j] = counter;
    if (i > 0)
    {
      if (j < n - 1)
      {
        if (square[i - 1][j + 1] == 0)
        {
          --i;
          ++j;
        }
        else if (i < n - 1)
        {
          ++i;
        }
      }
      else
      {
        j = 0;
        --i;
      }
    }
    else
    {
      if (j < n - 1)
      {
        i = n - 1;
        ++j;
      }
      else
      {
        ++i;
      }
    }
    ++counter;
  }
}

void DoubleEvenMagicSquare(int **square, int n)
{
  int counter = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      square[i][j] = counter;
      ++counter;
    }
  }
  for (int i = 0; i < n / 2; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i >= n / 4 && i < n / 2 && (j < n / 4 || j >= 3 * n / 4) || (i < n / 4 && j >= n / 4 && j < 3 * n / 4))
      {
        int buf = square[n - 1 - i][n - 1 - j];
        square[n - 1 - i][n - 1 - j] = square[i][j];
        square[i][j] = buf;
      }
    }
  }
}

void SingleEvenMagicSquare(int **square, int n)
{
  int halfN = n / 2;
  int subSquareSize = halfN * halfN;

  int **subSquare = (int **)malloc(halfN * sizeof(int *));
  for (int i = 0; i < halfN; i++)
  {
    subSquare[i] = (int *)malloc(halfN * sizeof(int));
  }

  for (int i = 0; i < halfN; i++)
  {
    for (int j = 0; j < halfN; j++)
    {
      subSquare[i][j] = 0;
    }
  }

  OddMagicSquare(subSquare, halfN);

  for (int i = 0; i < halfN; i++)
  {
    for (int j = 0; j < halfN; j++)
    {
      int val = subSquare[i][j];
      square[i][j] = val;
      square[i + halfN][j] = val + 3 * subSquareSize;
      square[i][j + halfN] = val + 2 * subSquareSize;
      square[i + halfN][j + halfN] = val + subSquareSize;
    }
  }

  int k = n/4;
  for (int i = 0; i < halfN; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (i == k && j == k-1)
      {
        continue;
      }
      int temp = square[i][j];
      square[i][j] = square[i + halfN][j];
      square[i + halfN][j] = temp;
    }
  }
  for (int i = 0; i < halfN; i++)
  {
    for (int j = n - k + 1; j < n; j++)
    {
      int temp = square[i][j];
      square[i][j] = square[i + halfN][j];
      square[i + halfN][j] = temp;
    }
  }

  int temp = square[k][k];
  square[k][k] = square[k + halfN][k];
  square[k + halfN][k] = temp;

  for (int i = 0; i < halfN; i++)
  {
    free(subSquare[i]);
  }
  free(subSquare);
}
