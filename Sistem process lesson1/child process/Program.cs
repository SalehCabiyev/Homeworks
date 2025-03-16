using System.Diagnostics;
using System;

Console.WriteLine($"child process start");


foreach (var arg in args)
{
    Console.WriteLine($"получен аргумент: {arg}");
    
};