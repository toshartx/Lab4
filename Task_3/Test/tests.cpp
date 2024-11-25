#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>

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

std::string SolveTask3(int **matrix, int n)
{
  int sum = 0, multiple = 1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i <= j && i + j <= n - 1 || i >= j && i + j >= n - 1)
      {
        sum += matrix[i][j];
        multiple *= matrix[i][j];
      }
    }
  }
  std::string sumStr = std::to_string(sum);
  std::string multipleStr = std::to_string(multiple);
  std::string result = sumStr + " " + multipleStr;
  return result;
}

TEST(SimpleTests, Test1)
{
  const int n = 3;
  int **arr = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = new int[n];
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      arr[i][j] = i*n + 2*j;
    }
  }

  arr[0][0] = 0;
  ASSERT_EQ(SolveTask3(arr, n), "35 0");
  deleteArray(arr, n);
}

TEST(SimpleTests, Test2)
{
  const int n = 3;
  int **arr = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = new int[n];
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      arr[i][j] = i * n + j + 1;
    }
  }
  ASSERT_EQ(SolveTask3(arr, n), "35 15120");
  deleteArray(arr, n);
}

TEST(SimpleTests, Test3)
{
  const int n = 1;
  int **arr = new int *[n];
  for (int i = 0; i < n; ++i)
  {
    arr[i] = new int[n];
  }
  arr[0][0] = 52;
  ASSERT_EQ(SolveTask3(arr, n), "52 52"); 
  deleteArray(arr, n);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}