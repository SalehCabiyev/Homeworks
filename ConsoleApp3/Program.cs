// See https://aka.ms/new-console-template for more information
using System;
class Proqram
{
    static void Main()
    {


        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 9, 1, 2, 3 };
        //int count1 = 0;
        //int count2 = 0;
        //for (int i = 0; i < arr.Length; i++)
        //{
        //    if (arr[i] % 2 == 0) { count2++; }
        //    else { count1++; }

        //}
        //Console.WriteLine($"even: {count2}");
        //Console.WriteLine($"odd: {count1}");

        //void CountUniqueElements(int[] arr)
        //{
        //    int unequecount = 0;
        //    bool isUnique = true;

        //    Array.Sort(arr);
        //    for (int i = 0; i < arr.Length; i++)
        //    {
        //        if (i == 0 || arr[i] != arr[i - 1])
        //        {
        //            isUnique = true;
        //            if (i < arr.Length-1 && arr[i] == arr[i + 1])
        //            {
        //                isUnique = false;
        //            }

        //            if (isUnique)
        //            {
        //                unequecount++;

        //            }
        //        }


        //    }
        //    Console.WriteLine($"unique: {unequecount}");

        //}

        //CountUniqueElements(arr);
        ////test2
        //Console.WriteLine("Enter number:");
        //int number = 0;
        //int numcount = 0;
        //int.TryParse(Console.ReadLine(), out number);
        //for (int i = 0; i < arr.Length; i++)
        //{
        //    if (arr[i] < number) { numcount++; }
        //}
        //Console.WriteLine($"количество значений меньших, чем {number} = {numcount}");
        //test3
        //int number_count= 0;
        //int number_1 = 0;
        //int number_2 = 0;
        //int number_3 = 0;
        //Console.WriteLine("Enter number 1:");
        //int.TryParse(Console.ReadLine(),out number_1);
        //Console.WriteLine("Enter number 2:");
        //int.TryParse(Console.ReadLine(), out number_2);
        //Console.WriteLine("Enter number 3:");
        //int.TryParse(Console.ReadLine(), out number_3);
        //for (int i = 0; i < arr.Length-2; i++)
        //{
        //    if (arr[i] == number_1 && arr[i + 1] == number_2 && arr[i + 2] == number_3)
        //    {
        //         number_count++;
        //    }


        //}
        //Console.WriteLine($"последовательность из этих трёх чисел встречается в массиве {number_count} раза");
        //test4
      
           
            Console.Write("Введите размерность первого массива (M): ");
            int M = int.Parse(Console.ReadLine());
            int[] array1 = new int[M];
            Console.WriteLine("Введите элементы первого массива:");
            for (int i = 0; i < M; i++)
            {
                array1[i] = int.Parse(Console.ReadLine());
            }

           
            Console.Write("Введите размерность второго массива (N): ");
            int N = int.Parse(Console.ReadLine());
            int[] array2 = new int[N];
            Console.WriteLine("Введите элементы второго массива:");
            for (int i = 0; i < N; i++)
            {
                array2[i] = int.Parse(Console.ReadLine());
            }

          
            int[] commonElements = new int[Math.Min(M, N)];
            int commonCount = 0;

           
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (array1[i] == array2[j])
                    {
                        
                        bool isDuplicate = false;
                        for (int k = 0; k < commonCount; k++)
                        {
                            if (commonElements[k] == array1[i])
                            {
                                isDuplicate = true;
                                break;
                            }
                        }

                       
                        if (!isDuplicate)
                        {
                            commonElements[commonCount] = array1[i];
                            commonCount++;
                        }
                    }
                }
            }

            
            Console.WriteLine("Общие элементы (без повторений):");
            for (int i = 0; i < commonCount; i++)
            {
                Console.WriteLine(commonElements[i]);
            }
        
    

    // test5

    //    int[,] array = {
    //    { 1, 2, 3 },
    //    { 4, 5, 6 },
    //    { 7, 8, 9 }
    //};


    //    int minValue = array[0, 0];
    //    int maxValue = array[0, 0];


    //    for (int i = 0; i < array.GetLength(0); i++) 
    //    {
    //        for (int j = 0; j < array.GetLength(1); j++) 
    //        {

    //            if (array[i, j] < minValue)
    //            {
    //                minValue = array[i, j];
    //            }


    //            if (array[i, j] > maxValue)
    //            {
    //                maxValue = array[i, j];
    //            }
    //        }
    //    }


    //    Console.WriteLine("Минимальное значение: " + minValue);
    //    Console.WriteLine("Максимальное значение: " + maxValue);
    //test6
    //Console.WriteLine("введите предложение:");
    //string sentence =Console.ReadLine();
    //string[] words = sentence.Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
    //int wordCount = words.Length;
    //Console.WriteLine("Количество слов в предложении: " + wordCount);

    //test 7
    //Console.WriteLine("введите предложение:");
    //string sentence1=Console.ReadLine();
    //string [] sentence_array=sentence1.Split();
    //for (int i = 0; i < sentence_array.Length; i++)
    //{
    //    char[] wordarray = sentence_array[i].ToCharArray();
    //    Array.Reverse(wordarray);
    //    sentence_array[i]=new string(wordarray);
    //}
    //string result = string.Join(" ", sentence_array);
    //Console.WriteLine(result);
    //test 8

    //        string vowels = "аеёиоуыэюяAEЁИОУЫЭЮЯ";


    //        Console.Write("Введите предложение на русском: ");
    //        string sentence = Console.ReadLine();

    //        int countVowels = 0;


    //        foreach (char c in sentence)
    //        {

    //            if (vowels.Contains(c))
    //            {
    //                countVowels++;
    //            }
    //        }


    //        Console.WriteLine($"Количество гласных букв в предложении: {countVowels}");
    //test 9

    //Console.Write("Введите исходную строку: ");
    //string inputString = Console.ReadLine();

    //Console.Write("Введите подстроку для поиска: ");
    //string substring = Console.ReadLine();


    //int count = 0;


    //int index = 0;


    //while ((index = inputString.IndexOf(substring, index)) != -1)
    //{
    //    count++;
    //    index += substring.Length;


    //    Console.WriteLine($"Количество вхождений подстроки: {count}");



    //}
}
}





