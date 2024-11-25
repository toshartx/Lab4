#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>

std::string SolveTask5(char *field, int n, int m)
{
  std::string result = "";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (*(field + i * m + j) == '*')
      {
        continue;
      }
      for (int x = i - 1; x <= i + 1; ++x)
      {
        for (int y = j - 1; y <= j + 1; ++y)
        {
          if (x >= 0 && y >= 0 && x < n && y < m && *(field + x * m + y) == '*')
          {
            if (*(field + i * m + j) == '.')
              *(field + i * m + j) += 3;
            else
              *(field + i * m + j) += 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      result += *(field + i * m + j);
    }
  }
  return result;
}

TEST(SimpleTests, Test1)
{
  const int n = 2;
  const int m = 2;
  char arr[n*m+1] = {"*..*"};
  ASSERT_EQ(SolveTask5(arr, n, m), "*22*");
}

TEST(SimpleTests, Test2)
{
  const int n = 1;
  const int m = 1;
  char arr[n*m+1] = {"*"};
  ASSERT_EQ(SolveTask5(arr, n, m), "*");
}

TEST(SimpleTests, Test3)
{
  const int n = 2;
  const int m = 2;
  char arr[n*m+1] = {"*..."};
  ASSERT_EQ(SolveTask5(arr, n, m), "*111");
}

TEST(NotSimpleTests, Test4)
{
  const int n = 3;
  const int m = 3;
  char arr[n*m+1] = {"****.****"};
  ASSERT_EQ(SolveTask5(arr, n, m), "****8****");
}

TEST(NotSimpleTests, Test5)
{
  const int n = 3;
  const int m = 3;
  char arr[n*m+1] = {"*..*..*.."};
  ASSERT_EQ(SolveTask5(arr, n, m), "*2.*3.*2.");
}

TEST(NotSimpleTests, Test6)
{
  const int n = 3;
  const int m = 3;
  char arr[n*m+1] = {"****..*.."};
  ASSERT_EQ(SolveTask5(arr, n, m), "****52*2.");
}

TEST(NotSimpleTests, Test7)
{
  const int n = 2;
  const int m = 3;
  char arr[n*m+1] = {"*..*.*"};
  ASSERT_EQ(SolveTask5(arr, n, m), "*31*3*");
}

TEST(NotSimpleTests, Test8)
{
  const int n = 5;
  const int m = 5;
  char arr[n*m+1] = {"******....*.****.*..*.*.*"};
  ASSERT_EQ(SolveTask5(arr, n, m), "******6564*5****6*63*4*3*");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}