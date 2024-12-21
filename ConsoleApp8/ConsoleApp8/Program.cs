// See https://aka.ms/new-console-template for more information
using System;


using ConsoleApp8;
class Program
{
    static void Main()
    {
        List<ICalculatorOperation> list = new List<ICalculatorOperation> {
        new Addition(),
        new Subtraction(),
        new Multiplication(),
        new Division()
        };
        while (true) {
            Console.WriteLine("Доступные операции:");
            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine($"{i + 1}.{list[i].Name}");

            }
            Console.WriteLine("Выберите операцию (1-4) или нажмите 0 для выхода:");
            string input = Console.ReadLine();
            if (input == "0")
            {
                break;
            }
            int operationIndex;
            if((!int.TryParse(input, out operationIndex))||operationIndex<1|| operationIndex > list.Count)
            {
                Console.WriteLine("Неверный выбор операции. Попробуйте снова.");
                continue;

            }
            Console.WriteLine("Enter a:");
            double a;
           if(!double.TryParse(Console.ReadLine(), out a))
            {
                Console.WriteLine("Некорректный ввод. Это не число.");
                continue;
            }
            double b;
            Console.WriteLine("Enter b:");
            if (!double.TryParse(Console.ReadLine(), out b))
            {
                Console.WriteLine("Некорректный ввод. Это не число.");
                continue;
            }
            try
            {
                var operation = list[operationIndex - 1];
                double result = operation.Execute(a, b);
                Console.WriteLine($"Результат: {result}");
            }
            catch(DivideByZeroException ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Произошла ошибка: {ex.Message}");
            }


        }
        }
}

