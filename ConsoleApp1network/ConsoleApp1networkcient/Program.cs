// Client.cs
using System.Net;
using System.Net.Sockets;
using System.Text;

var client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
await client.ConnectAsync(new IPEndPoint(IPAddress.Loopback, 3003));

Console.WriteLine(" Подключено к серверу");

Task.Run(async () =>
{
    var buffer = new byte[1024];
    while (true)
    {
        int received = await client.ReceiveAsync(buffer);
        if (received == 0) break;

        string message = Encoding.UTF8.GetString(buffer, 0, received);
        Console.WriteLine($"Сервер: {message}");
    }
});

while (true)
{
    string? input = Console.ReadLine();
    if (input?.ToLower() == "quit") break;

    byte[] data = Encoding.UTF8.GetBytes(input);
    await client.SendAsync(data);
}

client.Shutdown(SocketShutdown.Both);
client.Close();
