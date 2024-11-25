#include <gtest/gtest.h>
#include <gmock/gmock.h>

int SolveTask1(int *arr, int k)
{
  double average = 0;

  for (int i = 0; i < k; ++i)
  {
    average += (double(arr[i])/k);
  }
  int counter = 0;
  for (int i = 0; i < k; ++i)
  {
    if (arr[i] - average > 1e-10)
    {
      ++counter;
    } 
  }
  return counter;  
}

TEST(SimpleTests, Test1)
{
  const int k = 4;
  int arr[k] = {2, 3, 4, 1};

  ASSERT_TRUE(SolveTask1(arr, k) == 2);
}

TEST(SimpleTests, Test2)
{
  const int k = 9;
  int arr[k] = {2, 3, 4, 1, 6, 9, 11, 0, 0};

  ASSERT_TRUE(SolveTask1(arr, k) == 3);
}

TEST(SimpleTests, Test3)
{
  const int k = 50;
  int arr[k];
  for (int i = 0; i < k; ++i)
  {
    arr[i] = 0;
  }

  ASSERT_TRUE(SolveTask1(arr, k) == 0);
}

TEST(NotSimpleTests, Test4)
{
  const int k = 5;
  int arr[k] = {1, 1, 3, 5, 5};

  ASSERT_TRUE(SolveTask1(arr, k) == 2);
}

TEST(NotSimpleTests, Test5)
{
  const int k = 501;
  int arr[k];
  for (int i = 0; i < k; ++i)
  {
    arr[i] = i + 1;
  }

  ASSERT_TRUE(SolveTask1(arr, k) == 250);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

