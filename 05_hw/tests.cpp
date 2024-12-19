#include <gtest/gtest.h>
#include "stack.h"

using namespace std;

class StackTest : public testing::Test
{
  void SetUp() override
  {
    stack = new Stack();
  }

  void TearDown() override {
    delete stack;
  }

  public:
    Stack* stack;
};

TEST_F(StackTest, isEmptyTest)
{
  ASSERT_EQ(isEmpty(stack), true);
}

TEST_F(StackTest, getTopTest)
{
  ASSERT_EQ(getTop(stack), nullptr);
}

TEST_F(StackTest, PushTest)
{
  push(stack, 3);
  push(stack, 5);
  ASSERT_EQ(getTop(stack)->data, 5);
}

TEST_F(StackTest, PopTest)
{
  push(stack, 3);
  pop(stack);
  ASSERT_EQ(getTop(stack), nullptr);
}

TEST_F(StackTest, EmptyPopTest)
{
  pop(stack);
  ASSERT_EQ(getTop(stack), nullptr);
}

TEST_F(StackTest, destroyStackTest)
{
  push(stack, 3);
  push(stack, 5);
  push(stack, 15);

  destroyStack(stack);

  ASSERT_EQ(getTop(stack), nullptr);
}

TEST_F(StackTest, searchByValueTest)
{
  push(stack, 3);
  push(stack, 5);
  push(stack, 15);
  ASSERT_EQ(searchByValue(stack, 5)->data, 5);
}

TEST_F(StackTest, searchByValueInvTest)
{
  ASSERT_EQ(searchByValue(stack, 5), nullptr);
}

TEST_F(StackTest, searchByIndexTest)
{
  push(stack, 3);
  push(stack, 5);
  push(stack, 15);
  ASSERT_EQ(searchByIndex(stack, 1)->data, 5);
}

TEST_F(StackTest, searchByIndexInvTest)
{
  ASSERT_EQ(searchByIndex(stack, 1), nullptr);
}

TEST_F(StackTest, traverseStackTest) {
  testing::internal::CaptureStdout();

  push(stack, 3);
  push(stack, 5);
  push(stack, 15);

  traverseStack(stack);

  std::string str = testing::internal::GetCapturedStdout();
  EXPECT_EQ("Stack elements: 15 5 3 \n", str);
}

TEST_F(StackTest, traverseStackEmptyTest) {
  testing::internal::CaptureStdout();

  traverseStack(stack);

  std::string str = testing::internal::GetCapturedStdout();
  EXPECT_EQ("Stack elements: \n", str);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}