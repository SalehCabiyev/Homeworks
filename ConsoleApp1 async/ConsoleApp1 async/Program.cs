using System;
using System.Security.Cryptography;

class Program
{
    #region Task 1
    public static async Task RandomNumbersAsync(int minnum,int maxnum)
    {
        
        await Task.Run(() =>
        {
            var list = new List<int>();
            var random = new Random();
            for (int i = 0; i < 20; i++)
            {
                list.Add(random.Next(minnum, maxnum));
            }
            foreach (var num in list)
            {
                Console.Write($"{num} ");
            }
        });

    }



    #endregion
    #region Task 2
    public static async Task<List<int>> FiterEvenNumbersAsync(List<int>numbers)
    {
        await Task.Delay(1500);
        
            
            var evennumbers = numbers.Where(n => n % 2 == 0).ToList();
            foreach (var num in evennumbers)
            {
                Console.Write($"{num} ");
            }
            return evennumbers;
            

       
    }
    #endregion

    #region Task 3
    public static async Task<List<int>> FilterOddAsync(List<int>numbers)
    {
        await Task.Delay(1500);
        var OddNumbers=numbers.Where(n => n %2 != 0).ToList();
        foreach (var num in OddNumbers)
        {
            Console.Write($"{num} ");
        }
        return OddNumbers;

    }

    #endregion
    #region Task 4
    public static async Task<int>CalkulateSumAsync(List<int>numbers)
    {
        await Task.Delay(1000);
        var sum=numbers.Sum();
        Console.WriteLine($"\nСумма чисел\n{sum}");
        return sum;
    }

    #endregion
   
    public static async Task Main(string[] args)
    {
        var list = new List<int> { 1,2,3,4,5,6,7,8,9,10};
        Console.WriteLine("Рандомные числа");
       await RandomNumbersAsync(1,101);
        Console.WriteLine("\nЧетные числа");
        await FiterEvenNumbersAsync(list);
        Console.WriteLine("\nНечетные числа");
        await FilterOddAsync(list);
        await CalkulateSumAsync(list);


    }
}