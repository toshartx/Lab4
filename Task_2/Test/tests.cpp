#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

void deleteArray (int** arr, int n)
{
  for (int i = 0; i < n; ++i)
  {
    delete[] arr[i];
    arr[i] = nullptr;
  }
  delete[] arr;
  arr = nullptr;
}

int SolveTask2(int** matrix, int m, int n)
{
  int result = 0;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i % 2 == 1)
      {
        result += matrix[i][j];
      }
    }
  }
  return result;
}

TEST(SimpleTests, Test1)
{
  const int m = 3;
  const int n = 3;
  int** arr = new int*[m];
  for (int i = 0; i < m; ++i)
  {
    arr[i] = new int[n];
  }
  
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      arr[i][j] = i*n + j + 1;
    }
  }

  ASSERT_TRUE(SolveTask2(arr, m, n) == 15);

  deleteArray(arr, m);
}

TEST(SimpleTests, Test2)
{
  const int m = 1;
  const int n = 10;
  int** arr = new int*[m];
  for (int i = 0; i < m; ++i)
  {
    arr[i] = new int[n];
  }
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      arr[i][j] = 100000;
    }
  }

  ASSERT_TRUE(SolveTask2(arr, m, n) == 0);

  deleteArray(arr, m);
}

TEST(SimpleTests, Test3)
{
  const int m = 3;
  const int n = 1;
  int** arr = new int*[m];
  for (int i = 0; i < m; ++i)
  {
    arr[i] = new int[n];
  }
  arr[0][0] = 75;
  arr[1][0] = 150;
  arr[2][0] = 300;

  ASSERT_TRUE(SolveTask2(arr, m, n) == 150);

  deleteArray(arr, m);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
