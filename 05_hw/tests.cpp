#include <gtest/gtest.h>
#include "stack.h"

using namespace std;

class StackTest : public testing::Test
{
  // Метод, который выполняется перед каждым тестом
  void SetUp() override
  {
    stack = new Stack(); // Создаем новый экземпляр стека
  }

  // Метод, который выполняется после каждого теста
  void TearDown() override {
    delete stack; // Удаляем стек, освобождая память
  }

  public:
    Stack* stack; // Указатель на стек, который будет использоваться в тестах
};

// Тест на проверку, что стек пустой
TEST_F(StackTest, isEmptyTest)
{
  ASSERT_EQ(isEmpty(stack), true); // Проверяем, что isEmpty возвращает true
}

// Тест на получение верхнего элемента стека
TEST_F(StackTest, getTopTest)
{
  ASSERT_EQ(getTop(stack), nullptr); // Проверяем, что верхний элемент равен nullptr (стек пуст)
}

// Тест на добавление элементов в стек
TEST_F(StackTest, PushTest)
{
  push(stack, 3); // Добавляем элемент 3
  push(stack, 5); // Добавляем элемент 5
  ASSERT_EQ(getTop(stack)->data, 5); // Проверяем, что верхний элемент равен 5
}

// Тест на удаление элемента из стека
TEST_F(StackTest, PopTest)
{
  push(stack, 3); // Добавляем элемент 3
  pop(stack);     // Удаляем верхний элемент
  ASSERT_EQ(getTop(stack), nullptr); // Проверяем, что стек пустой (nullptr)
}

// Тест на попытку удалить элемент из пустого стека
TEST_F(StackTest, EmptyPopTest)
{
  pop(stack); // Пытаемся удалить элемент из пустого стека
  ASSERT_EQ(getTop(stack), nullptr); // Проверяем, что стек все еще пустой
}

// Тест на уничтожение стека
TEST_F(StackTest, destroyStackTest)
{
  push(stack, 3);   // Добавляем элементы в стек
  push(stack, 5);
  push(stack, 15);

  destroyStack(stack); // Уничтожаем стек

  ASSERT_EQ(getTop(stack), nullptr); // Проверяем, что стек пустой (nullptr)
}

// Тест на поиск элемента по значению
TEST_F(StackTest, searchByValueTest)
{
  push(stack, 3);
  push(stack, 5);
  push(stack, 15);
  
  ASSERT_EQ(searchByValue(stack, 5)->data, 5); // Проверяем, что найденный элемент равен 5
}

// Тест на поиск элемента по значению (не найдено)
TEST_F(StackTest, searchByValueInvTest)
{
  ASSERT_EQ(searchByValue(stack, 5), nullptr); // Проверяем, что поиск возвращает nullptr (не найдено)
}

// Тест на поиск элемента по индексу
TEST_F(StackTest, searchByIndexTest)
{
  push(stack, 3);
  push(stack, 5);
  push(stack, 15);
  
  ASSERT_EQ(searchByIndex(stack, 1)->data, 5); // Проверяем, что элемент с индексом 1 равен 5
}

// Тест на поиск элемента по индексу (не найдено)
TEST_F(StackTest, searchByIndexInvTest)
{
  ASSERT_EQ(searchByIndex(stack, 1), nullptr); // Проверяем, что поиск возвращает nullptr (не найдено)
}

// Тест на обход стека и вывод его элементов
TEST_F(StackTest, traverseStackTest) {
  testing::internal::CaptureStdout(); // Захватываем стандартный вывод

  push(stack, 3);
  push(stack, 5);
  push(stack, 15);

  traverseStack(stack); // Обходим стек и выводим элементы

  std::string str = testing::internal::GetCapturedStdout(); // Получаем захваченный вывод
  EXPECT_EQ("Stack elements: 15 5 3 \n", str); // Проверяем правильность вывода
}

// Тест на обход пустого стека
TEST_F(StackTest, traverseStackEmptyTest) {
  testing::internal::CaptureStdout(); // Захватываем стандартный вывод

  traverseStack(stack); // Обходим пустой стек

  std::string str = testing::internal::GetCapturedStdout(); // Получаем захваченный вывод
  EXPECT_EQ("Stack elements: \n", str); // Проверяем правильность вывода для пустого стека
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv); // Инициализируем Google Test

  return RUN_ALL_TESTS(); // Запускаем все тесты и возвращаем результат
}