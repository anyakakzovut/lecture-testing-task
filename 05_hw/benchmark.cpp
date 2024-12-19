#include <benchmark/benchmark.h>
#include "stack.h" 

class StackBench : public benchmark::Fixture
{
  // Метод, который выполняется перед каждым бенчмарком
  void SetUp(::benchmark::State& state)
  {
    stack = new Stack(); // Создаем новый экземпляр стека
  }

  // Метод, который выполняется после каждого бенчмарка
  void TearDown(::benchmark::State& state)
  {
    delete stack; // Удаляем стек, освобождая память
  }

public:
  Stack* stack; // Указатель на стек, который будет использоваться в бенчмарках
};

// Определяем бенчмарк для измерения времени выполнения операции добавления элементов в стек
BENCHMARK_DEFINE_F(StackBench, PushBench)(benchmark::State& st)
{
  for (auto _ : st) // Цикл для повторного выполнения теста
  {
    for(int i = 0; i < st.range(0); i++) // Внутренний цикл для добавления элементов в стек
      push(stack, i); // Добавляем элемент i в стек
  }
}

// Определяем бенчмарк для измерения времени выполнения операции удаления элементов из стека
BENCHMARK_DEFINE_F(StackBench, PopBench)(benchmark::State& st)
{
  for(int i = 0; i < st.range(0); i++) // Сначала заполняем стек элементами
    push(stack, i); // Добавляем элемент i в стек

  for (auto _ : st) // Цикл для повторного выполнения теста
  {
    for(int i = 0; i < st.range(0); i++) // Внутренний цикл для удаления элементов из стека
      pop(stack); // Удаляем верхний элемент из стека
  }
}

// Регистрируем бенчмарки с различными аргументами (размером стека)
BENCHMARK_REGISTER_F(StackBench, PushBench)
    ->Arg(100)       // Размер стека 100
    ->Arg(1000)      // Размер стека 1000
    ->Arg(10000)     // Размер стека 10000
    ->Arg(100000)    // Размер стека 100000
    ->Arg(1000000);  // Размер стека 1000000

// Регистрируем бенчмарк для удаления элементов с теми же аргументами
BENCHMARK_REGISTER_F(StackBench, PopBench)
    ->Arg(100)       
    ->Arg(1000)      
    ->Arg(10000)     
    ->Arg(100000)    
    ->Arg(1000000);

BENCHMARK_MAIN();