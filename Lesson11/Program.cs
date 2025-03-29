using Lesson11;
using Lesson11.Implementations;
using Lesson11.Interfaces;

Menu menu = new();
IMovieService movieService = new MovieService();
IFileService fileService = new FileService();
fileService.Load();

menu.DisplayMenu();

bool flag = true;
while (flag)
{
  
    MenuChoice choice = menu.GetMenuChoice();
    switch (choice.Id)
    {
        case 1:
            Console.WriteLine($"You chose {choice.Description}");

            Console.WriteLine("Enter movie name:");
            var movieName = Console.ReadLine();
            
            var res = movieService.SearchMovie(movieName);

            foreach (var movie in res.results)
            {
                Console.WriteLine(movie);
            }
            fileService.Save(res);
           
            

            break;
        case 2:
            Console.WriteLine($"You chose {choice.Description}");
            break;
        case 3:
            flag = false;
            Console.WriteLine("Exit");
            break;
        case 4:
            fileService.Delete();
            
            break;
       
        default:
            Console.WriteLine("Invalid choice");
            break;
    }
}

Console.WriteLine("Goodbye!");