using System.Net;
using System.Net.Sockets;
using System.Text;

Console.WriteLine("Выберите как хотите войти в систему");
Console.WriteLine("1.Сервер");
Console.WriteLine("2.Клиент");
int.TryParse(Console.ReadLine(), out int choice);
if (choice == 1)
{
    TcpListener server = new TcpListener(IPAddress.Parse("192.168.0.105"), 5000);
    server.Start();
    Console.WriteLine("Ожидаем подключения клиента...");

    TcpClient client = new TcpClient();
    client = await server.AcceptTcpClientAsync();
    Console.WriteLine("Клиент подключен.");
    Console.WriteLine("Напишите 'quit' чтобы завершит чат");

    NetworkStream stream1 = client.GetStream();
    using var reader = new StreamReader(stream1, Encoding.UTF8, false, 1024, true);

    Task.Run(async () =>
    {
        while (true)
        {
            string json = await reader.ReadLineAsync();
            Console.WriteLine($"Сервер: {json}");
        }
    });

    while (true)
    {
        string? a = Console.ReadLine();
        if (a.ToLower().Trim() == "quit") { return; }

        byte[] buffer = Encoding.UTF8.GetBytes(a+"\n");

        await stream1.WriteAsync(buffer);

    }



}
else
{
    try
    {
        TcpClient client2 = new TcpClient();
        await client2.ConnectAsync(IPAddress.Parse("192.168.0.105"), 5000);
        Console.WriteLine("Подключено к серверу.");
        Console.WriteLine("Напишите 'quit' чтобы завершит чат");

        NetworkStream stream2 = client2.GetStream();
                    using var reader = new StreamReader(stream2, Encoding.UTF8, false, 1024, true);

        Task.Run(async () =>
        {
            while (true)
            {
                string json = await reader.ReadLineAsync();
                Console.WriteLine($"Клиент: {json}");
            }

        });
        while (true)
        {

            string? a = Console.ReadLine();
            if (a.ToLower().Trim() == "quit") { return; }


            byte[] buffer = Encoding.UTF8.GetBytes(a+"\n");

            await stream2.WriteAsync(buffer);

        }


    }
    catch (Exception ex) { Console.WriteLine(ex.Message); return; }

}
