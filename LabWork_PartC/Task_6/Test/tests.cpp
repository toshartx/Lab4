#include <gtest/gtest.h>
#include <gmock/gmock.h>

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

  int k = n / 4;
  for (int i = 0; i < halfN; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (i == k && j == k - 1)
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

bool SolveTask6(int **magicSquare, int n)
{
  bool checkFlag = 1;
  int magicConst = n * (n * n + 1) / 2;
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

  int sum = 0;
  // Сумма по строкам
  for (int i = 0; i < n; ++i)
  {
    sum = 0;
    for (int j = 0; j < n; ++j)
    {
      sum += magicSquare[i][j];
    }
    if (sum != magicConst)
    {
      checkFlag = 0;
      return checkFlag;
    }
  }
  // Сумма по столбцам
  for (int i = 0; i < n; ++i)
  {
    sum = 0;
    for (int j = 0; j < n; ++j)
    {
      sum += magicSquare[j][i];
    }
    if (sum != magicConst)
    {
      checkFlag = 0;
      return checkFlag;
    }
  }

  sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += magicSquare[i][i];
  }
  if (sum != magicConst)
  {
    checkFlag = 0;
    return checkFlag;
  }

  sum = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += magicSquare[n-1-i][i];
  }
  if (sum != magicConst)
  {
    checkFlag = 0;
    return checkFlag;
  }
  return checkFlag;
}

TEST(SimpleTests, Test1)
{
  int n = 3;
  int **magicSquare = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    magicSquare[i] = new int[n]{};
  }

  ASSERT_TRUE(SolveTask6(magicSquare, n));

  for (int i = 0; i < n; ++i)
  {
    delete[] magicSquare[i];
    magicSquare[i] = nullptr;
  }
  delete[] magicSquare;
  magicSquare = nullptr;
}

TEST(NotSimpleTests, Test2)
{
  int n = 1001;
  int **magicSquare = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    magicSquare[i] = new int[n]{};
  }

  ASSERT_TRUE(SolveTask6(magicSquare, n));

  for (int i = 0; i < n; ++i)
  {
    delete[] magicSquare[i];
    magicSquare[i] = nullptr;
  }
  delete[] magicSquare;
  magicSquare = nullptr;
}

TEST(SimpleTests, Test3)
{
  int n = 6;
  int **magicSquare = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    magicSquare[i] = new int[n]{};
  }

  ASSERT_TRUE(SolveTask6(magicSquare, n));
  for (int i = 0; i < n; ++i)
  {
    delete[] magicSquare[i];
    magicSquare[i] = nullptr;
  }
  delete[] magicSquare;
  magicSquare = nullptr;
}

TEST(NotSimpleTests, Test4)
{
  int n = 1000;
  int **magicSquare = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    magicSquare[i] = new int[n]{};
  }

  ASSERT_TRUE(SolveTask6(magicSquare, n));
  for (int i = 0; i < n; ++i)
  {
    delete[] magicSquare[i];
    magicSquare[i] = nullptr;
  }
  delete[] magicSquare;
  magicSquare = nullptr;
}

TEST(NotSimpleTests, Test5)
{
  int n = 1002;
  int **magicSquare = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    magicSquare[i] = new int[n]{};
  }

  ASSERT_TRUE(SolveTask6(magicSquare, n));
  for (int i = 0; i < n; ++i)
  {
    delete[] magicSquare[i];
    magicSquare[i] = nullptr;
  }
  delete[] magicSquare;
  magicSquare = nullptr;
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}