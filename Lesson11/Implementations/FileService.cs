using System.Text.Json;
using Lesson11.Data.Model;
using Lesson11.Interfaces;

namespace Lesson11.Implementations;

public class FileService : IFileService
{
    List<MovieSearchResult> files = new List<MovieSearchResult>();

    public void Save(MovieSearchResult result)
    {
        files.Add(result);
        var json=JsonSerializer.Serialize(files);
        File.WriteAllText("C:\\Users\\USER\\Desktop\\FSDE_1_24_3_RU-\\Lesson11\\result.json", json);
    }
    public void Delete()
    {
        if (files.Count == 0) { Console.WriteLine("историә  резултатов пустаә");return;  }
        int count = 0;
        foreach (var movie in files)
        {
            if (files.Count == 0)
            {
                Console.WriteLine("историә  резултатов пустаә");return;

            }
            Console.WriteLine($"{count}. {movie}");
            count++;
            
            
        }
        Console.WriteLine("Введите номер резулғтата :");
        int.TryParse(Console.ReadLine(), out int choice);
        files.RemoveAt(choice);

        var json=JsonSerializer.Serialize(files);
        File.WriteAllText("C:\\Users\\USER\\Desktop\\FSDE_1_24_3_RU-\\Lesson11\\result.json", json);
        Console.WriteLine("Удаление успешно");
    }
    public void Load() 
    {
       
        var json = File.ReadAllText("C:\\Users\\USER\\Desktop\\FSDE_1_24_3_RU-\\Lesson11\\result.json");
        if (string.IsNullOrWhiteSpace(json)) { return; }
        var newresults = JsonSerializer.Deserialize<List<MovieSearchResult>>(json);
        files.AddRange(newresults);
    }
    
}