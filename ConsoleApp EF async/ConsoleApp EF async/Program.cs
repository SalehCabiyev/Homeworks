using System;
using ConsoleApp_EF_async;
using Microsoft.EntityFrameworkCore;
class Program
{
    public async static Task Main()
    {

        using var context = new AppDBContext();
        context.Database.Migrate();
        string name = "Saleh";
        context.AddStudentManually(name);
        context.ShowAllStudentsManually();
        string name2 = "Elvin";
        await context.AddStudentAsync(name2);
        await context.ShowAllStudensAsync();
        
    }
}