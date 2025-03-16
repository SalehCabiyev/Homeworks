
using System.Diagnostics;
using System;

public class Program
{
    public static void Main(string[] args)
    {

        Console.WriteLine($"child process  whith id{Process.GetCurrentProcess().Id} started");
        if (args.Length != 3)
        {
            Console.WriteLine("Необходимы три аргумента:да числа и операция ");

        }
        try
        {
            double num1 = Convert.ToDouble(args[0]);
            double num2 = Convert.ToDouble(args[1]);
            string operation = args[2];

            double result = 0;

            switch (operation)
            {
                case "+":
                    result = num1 + num2;
                    break;

                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    if (num2 != 0)
                    {
                        result = num1 / num2;
                    }
                    else
                    {
                        Console.WriteLine("Ошибка: деление на ноль!");
                        return;
                    }
                    break;
                default:
                    Console.WriteLine("Неизвестная операция!");
                    return;


            }
            Console.WriteLine($"Результат: {result}");


        }
        catch (FormatException)
        {
            Console.WriteLine("Ошибка: аргументы должны быть числами.");
        }
    }
}