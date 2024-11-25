#include <stdio.h>
#include <stdlib.h>

short RestartProgramm();
void ContextMenu();
int ArraySizeInput();
void ArrayElementInput(int, int);
char CharInput();

int main()
{
  short RestartFlag = RestartProgramm();
  while (RestartFlag != 0)
  {
    ContextMenu();
    printf("Количество строк: ");
    int n = ArraySizeInput();
    printf("Количество столбцов: ");
    int m = ArraySizeInput();
    char **field = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < m; ++i)
    {
      field[i] = (char *)malloc(m * sizeof(char));
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        field[i][j] = '.';
      }
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        ArrayElementInput(i, j);
        field[i][j] = CharInput();
      }
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (field[i][j] == '*')
        {
          continue;
        }
        for (int x = i - 1; x <= i + 1; ++x)
        {
          for (int y = j - 1; y <= j+1; ++y)
          {
            if (x >= 0 && y >= 0 && x < n && y < m && field[x][y] == '*')
            {
              if (field[i][j] == '.') field[i][j] += 3;
              else field[i][j] += 1;
            }
          }
        }
      }
    }

    printf("Поле для игры: ");
    for (int i = 0; i < n; ++i)
    {
      printf("\n");
      for (int j = 0; j < m; ++j)
      {
        printf("%c%s", field[i][j], " ");
      }
    }

    for (int i = 0; i < m; ++i)
    {
      free(field[i]);
      field[i] = NULL;
    }
    free(field);
    field = NULL;

    RestartFlag = RestartProgramm();
  }
  return 0;
}

int ArraySizeInput()
{
  int a;
  while (!(scanf("%d", &a)) || getchar() != '\n' || a < 0)
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
  printf("Строится поле для игры Сапёр (клетка заполняется бомбой(*) и точкой(.) в случае, если бомба не ставится).\n");
  printf("Выводится поле, заполненное цифрами от 1 до 8 в соответствии с правилами игры.\n");
  printf("* 2 1 .\n");
  printf("2 * 2 1\n");
  printf("1 2 * 2              - пример заполнения поля.\n");
  printf(". 1 2 * \n");
  printf(" \n");
  printf("----------------------------------------------------------------------------------------------------\n");
}

void ArrayElementInput(int i, int j)
{
  printf("Введите бомбочку (*) или (.), если не хотите ставить бомбочку: ");
  printf("%d", i);
  printf("%d", j);
  printf(" ");
}

short RestartProgramm()
{
  printf("\nВведите 0, чтобы завершить программу\n        1, чтобы запустить программу\n");
  short a;

  while (!(scanf("%hd", &a)) || getchar() != '\n' || a != 0 && a != 1)
  {
    fflush(stdin);
    while (getchar() != '\n')
      ;
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}

char CharInput()
{
  char a;
  while (!(scanf("%c", &a)) || getchar() != '\n' || a != '*' && a != '.')
  {
    fflush(stdin);
    while (getchar() != '\n')
      ;
    printf("Ошибка ввода. Повторите попытку:\n");
  }
  return a;
}

