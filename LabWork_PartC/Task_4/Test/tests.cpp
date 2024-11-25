#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>

void deleteArray(int ***arr, int n)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      delete[] arr[i][j];
      arr[i][j] = nullptr;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    delete[] arr[i];
    arr[i] = nullptr;
  }
  delete[] arr;
  arr = nullptr;
}

std::string SolveTask4(int ***cube, int n)
{
  int sum[4] = {0, 0, 0, 0};
  if (n == 1)
  {
    return std::to_string(cube[0][0][0]);
  }

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

  std::string result;
  if (minimumSum == sum[0])
  {
    for (int i = 0, j = 0, k = 0; i < n; ++i, ++j, ++k)
    {
      result += (std::to_string(cube[i][j][k]) + " ");
    }
    result += '\n';
  }
  if (minimumSum == sum[1])
  {
    for (int i = 0, j = 0, k = n - 1; i < n; ++i, ++j, --k)
    {
      result += (std::to_string(cube[i][j][k]) + " ");
    }
    result += '\n';
  }
  if (minimumSum == sum[2])
  {
    for (int i = 0, j = n - 1, k = 0; i < n; ++i, --j, ++k)
    {
      result += (std::to_string(cube[i][j][k]) + " ");
    }
    result += '\n';
  }
  if (minimumSum == sum[3])
  {
    for (int i = 0, j = n - 1, k = n - 1; i < n; ++i, --j, --k)
    {
      result += (std::to_string(cube[i][j][k]) + " ");
    }
    result += '\n';
  }

  return result;
}

TEST(SimpleTests, Test1)
{
  int n = 2;
  int ***cube = new int**[n];
  for (int i = 0; i < n; ++i)
  {
    cube[i] = new int*[n];
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cube[i][j] = new int[n];
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        cube[i][j][k] = 1;
      }
    }
  }

  cube[0][0][0] = 0;
  cube[1][1][1] = 0;

  ASSERT_EQ(SolveTask4(cube, n), "0 0 \n");
  deleteArray(cube, n);
}

TEST(NotSimpleTests, Test2)
{
  int n = 2;
  int ***cube = new int**[n];
  for (int i = 0; i < n; ++i)
  {
    cube[i] = new int*[n];
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cube[i][j] = new int[n];
    }
  }
                                          
  for (int i = 0; i < n; ++i)           
  {                                     
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        cube[i][j][k] = i * n * n + j * n + k + 1;
      }
    }
  }
  ASSERT_EQ(SolveTask4(cube, n), "1 8 \n2 7 \n3 6 \n4 5 \n");
  deleteArray(cube, n);
}

TEST(SimpleTests, Test3)
{
  int n = 1;
  int ***cube = new int**[n];
  for (int i = 0; i < n; ++i)
  {
    cube[i] = new int*[n];
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cube[i][j] = new int[n];
    }
  }

  cube[0][0][0] = 52;
  ASSERT_EQ(SolveTask4(cube, n), "52");
  deleteArray(cube, n);
}

TEST(NotSimpleTests, Test4)
{
  int n = 3;
  int ***cube = new int**[n];
  for (int i = 0; i < n; ++i)
  {
    cube[i] = new int*[n];
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cube[i][j] = new int[n];
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        cube[i][j][k] = 101 + k + j*n + i*n*n;
      }
    }
  }
 
  ASSERT_EQ(SolveTask4(cube, n), "101 114 127 \n103 114 125 \n107 114 121 \n109 114 119 \n");
  deleteArray(cube, n);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}