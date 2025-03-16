
using System;

class ChildProcess
{
    public static void Main(string[] args)
    {
        string filePath = args[0];
        string searchWord = args[1];

        if (!File.Exists(filePath))
        {
            Console.WriteLine($"Ошибка: файл {filePath} не найден!");
            return;

        }
        try
        {
            string fileContent = File.ReadAllText(filePath);
            int wordCount = CountWordOccurrences(fileContent, searchWord);
            Console.WriteLine($"Слово '{searchWord}' встречается в файле {wordCount} раз.");

        }
        catch( Exception ex )  
        {
            Console.WriteLine($"Ошибка при чтении из фајла:{ex.Message}");

        }

        static int CountWordOccurrences(string text,string word)
        {
            int count = 0;
            int index = 0;

            while ((index = text.IndexOf(word, index, StringComparison.OrdinalIgnoreCase))!= -1)
            {
                count++;
                index += word.Length;
            }
            return count ;
        }
    }

}
