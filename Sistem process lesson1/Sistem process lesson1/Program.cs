
using System.Diagnostics;
using System;
using System.IO;
#region Test1
//Console.WriteLine($"Process with id {Process.GetCurrentProcess().Id} started");
//string childapp = "C:\\Users\\USER\\source\\repos\\Sistem process lesson1\\child process\\bin\\Debug\\net8.0\\child process.exe";

//ProcessStartInfo psi= new ProcessStartInfo
//{ FileName = childapp ,
//    Arguments="arg1 arg2 arg3",
//    RedirectStandardOutput=true
//};


//using Process process = new Process { StartInfo=psi};
//process.EnableRaisingEvents = true;
//process.Exited += (sender, e) => Console.WriteLine($"Child process with id {process.Id} finished ");
//process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);
//process.Start();
//Console.WriteLine($"Child process with id {process.Id} started");
//process.BeginOutputReadLine();
//process.WaitForExit();
//Console.WriteLine($"Process with id {Process.GetCurrentProcess().Id} finished ");
#endregion

#region Test2
//string childAppName = "C:\\Users\\USER\\source\\repos\\Sistem process lesson1\\child process\\bin\\Debug\\net8.0\\child process.exe";
//ProcessStartInfo processStartInfo = new ProcessStartInfo
//{
//    FileName = childAppName,
//    Arguments="arg1 arg2 arg3",
//    UseShellExecute = false,
//    RedirectStandardOutput = true,

//};
//using Process process = new Process {StartInfo=processStartInfo};
//process.OutputDataReceived += (sender, e) =>
//{
//    if (e.Data != null)
//    {
//        Console.WriteLine("дочерниј проүесс вывел:" + e.Data);
//    }
//};
//process.Start();
//process.BeginOutputReadLine();


//Console.WriteLine("\n выберите деүствие:");
//Console.WriteLine("1.Подождать завершения дочернего процесса и отобразить код завершения.");
//Console.WriteLine("2.Принудительно завершить дочерний процесс.");
//string choise=Console.ReadLine();
//if (choise == "1")
//{
//    process.WaitForExit();
//    Console.WriteLine($"Дочерний процесс завершился с кодом: {process.ExitCode} ");
//}
//else if (choise == "2")
//{
//    Console.WriteLine("Принудительное завершение дочернего процесса...");
//    process.Kill();
//    Console.WriteLine("Дочерний процесс завершен принудительно.");
//}
//else
//{
//    Console.WriteLine($"Неверный выбор");
//}
//Console.WriteLine("Родительский процесс завершен.");

#endregion

#region Test3 

//Console.WriteLine("Введите первое число");
//string input1 = Console.ReadLine();
//Console.WriteLine("введите второе число");
//string input2 = Console.ReadLine();
//Console.WriteLine("введите операцию  (+,-,*,/)");
//string operation = Console.ReadLine();
//if(!double.TryParse(input1,out double num1) || !double.TryParse(input2,out double num2 ))
//{
//    Console.WriteLine("Ошибка:оба ввода должны бытғ числами ");
//    return;
//}

//string childAppName = "C:\\Users\\USER\\source\\repos\\Sistem process lesson1\\child processcakulate\\bin\\Debug\\net8.0\\child processcalkulate.exe";


//ProcessStartInfo processStartInfo =new ProcessStartInfo 
//{
//    FileName= childAppName,
//    Arguments=$"{num1} {num2} {operation}",
//    UseShellExecute = false,
//    RedirectStandardOutput=true


//};

//Process process=new Process { StartInfo=processStartInfo};
//process.EnableRaisingEvents = true;

//process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);
//process.Start();
//process.BeginOutputReadLine();
//process.WaitForExit();



#endregion

#region Test4

//string ChildNameApp = "C:\\Users\\USER\\source\\repos\\Sistem process lesson1\\childprocesstest4\\bin\\Debug\\net8.0\\childprocesstest4.exe";
//string filePath = "C:\\Users\\USER\\source\\repos\\Sistem process lesson1\\Sistem process lesson1\\bin\\Debug\\net8.0\\text.json";
//string searchWord="bicycle";
//if (!File.Exists(filePath))
//{
//    Console.WriteLine($"Ошибка: файл {filePath} не существует!");
//    return;
//}
//ProcessStartInfo processStartInfo = new ProcessStartInfo 
//{
//    FileName=ChildNameApp,
//    Arguments=$"\"{filePath}\" \"{searchWord}\"",
//    UseShellExecute=false,
//    RedirectStandardOutput=true,


//};
//Process process = new Process { StartInfo=processStartInfo};

//process.EnableRaisingEvents = true;
//process.OutputDataReceived += (sender, e) => { Console.WriteLine(e.Data); };
//process.Start();
//process.BeginOutputReadLine();
//process.WaitForExit();



#endregion

