#include <stdio.h>
#include <stdlib.h>

short RestartProgramm();
void ContextMenu();
int ArraySizeInput();
void ArrayElementInput(int, int, int);
int IntInput();

int main()
{
  short RestartFlag = RestartProgramm();
  while (RestartFlag != 0)
  {
    ContextMenu();
    int n = ArraySizeInput();
    int ***cube = (int ***)malloc(sizeof(int **) * n);
    for (int i = 0; i < n; ++i)
    {
      cube[i] = (int **)malloc(sizeof(int *) * n);
    }
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        cube[i][j] = (int *)malloc(sizeof(int) * n);
      }
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        for (int k = 0; k < n; ++k)
        {
          ArrayElementInput(i, j, k);
          cube[i][j][k] = IntInput();
        }
      }
    }

    int sum[4] = {0, 0, 0, 0};

    for (int i = 0, j = 0, k = 0; i < n; ++i, ++j, ++k)
    {
      sum[0] += cube[i][j][k];
    }

    for (int i = 0, j = 0, k = n - 1; i < n; ++i, ++j, --k)
    {
      sum[1] += cube[i][j][k];
    }

    for (int i = 0, j = n - 1, k = 0; i < n; ++i, --j, ++k)
    {
      sum[2] += cube[i][j][k];
    }

    for (int i = 0, j = n - 1, k = n - 1; i < n; ++i, --j, --k)
    {
      sum[3] += cube[i][j][k];
    }

    int minimumSum = sum[0];
    for (int i = 0; i < 3; ++i)
    {
      if (sum[i + 1] < sum[i])
      {
        minimumSum = sum[i + 1];
      }
    }

    printf("Наименьшая диагональ (или диагонали):\n");
    if (minimumSum == sum[0])
    {
      for (int i = 0, j = 0, k = 0; i < n; ++i, ++j, ++k)
      {
        printf("%d", cube[i][j][k]);
        printf(" ");
      }
      printf("\n");
    }
    if (minimumSum == sum[1])
    {
      for (int i = 0, j = 0, k = n - 1; i < n; ++i, ++j, --k)
      {
        printf("%d", cube[i][j][k]);
        printf(" ");
      }
      printf("\n");
    }
    if (minimumSum == sum[2])
    {
      for (int i = 0, j = n - 1, k = 0; i < n; ++i, --j, ++k)
      {
        printf("%d", cube[i][j][k]);
        printf(" ");
      }
      printf("\n");
    }
    if (minimumSum == sum[3])
    {
      for (int i = 0, j = n - 1, k = n - 1; i < n; ++i, --j, --k)
      {
        printf("%d", cube[i][j][k]);
        printf(" ");
      }
      printf("\n");
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        free(cube[i][j]);
        cube[i][j] = NULL;
      }
    }
    for (int i = 0; i < n; ++i)
    {
      free(cube[i]);
      cube[i] = NULL;
    }
    free(cube);
    cube = NULL;

    RestartFlag = RestartProgramm();
  }
  return 0;
}

int ArraySizeInput()
{
  int a;
  printf("Введите порядок кубической матрицы: ");
  while (!(scanf("%d", &a)) || getchar() >= 48 && getchar() <= 57 || a < 0)
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
  printf("Вводится динамически кубическая матрица порядка n. Выводится диагональ, с наибольшей суммой чисел.\n");
  printf("  ________\n");
  printf(" /_______/|\n");
  printf(" |1      ||                - это типа куб.\n");
  printf(" |   2   ||\n");
  printf(" |______3|/\n");

  printf("----------------------------------------------------------------------------------------------------\n");
}

void ArrayElementInput(int i, int j, int k)
{
  printf("Введите элемент ");
  printf("%d", i);
  printf("%d", j);
  printf("%d", k);
  printf(" ");
}

short RestartProgramm()
{
  printf("Введите 0, чтобы завершить программу\n        1, чтобы запустить программу\n");
  short a;

  while (!(scanf("%hd", &a)) || getchar() >= 48 && getchar() <= 57 || a != 0 && a != 1)
  {
    fflush(stdin);
    while (getchar() != '\n')
      ;
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}

int IntInput()
{
  int a;
  while (!(scanf("%d", &a)) || getchar() >= 48 && getchar() <= 57 || a < 0)
  {
    fflush(stdin);
    while (getchar() != '\n')
      ;
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}