// Server.cs
using System.Net;
using System.Net.Sockets;
using System.Text;

var serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
serverSocket.Bind(new IPEndPoint(IPAddress.Loopback, 3003));
serverSocket.Listen();

Console.WriteLine(" Сервер слушает...");

var client = await serverSocket.AcceptAsync();
Console.WriteLine($" Клиент подключился: {client.RemoteEndPoint}");

Task.Run(async () =>
{
    var buffer = new byte[1024];
    while (true)
    {
        int received = await client.ReceiveAsync(buffer);
        if (received == 0) break;

        string message = Encoding.UTF8.GetString(buffer, 0, received);
        Console.WriteLine($"Клиент: {message}");
        
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
