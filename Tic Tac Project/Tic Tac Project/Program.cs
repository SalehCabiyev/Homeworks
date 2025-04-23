// Проект: Server
// Файл: Program.cs
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;

Game game = new();
TcpListener server = new TcpListener(IPAddress.Parse("127.0.0.1"), 5000);
server.Start();
Console.WriteLine("Ожидаем подключения клиента...");

TcpClient client = await server.AcceptTcpClientAsync();
Console.WriteLine("Клиент подключен.");

Console.WriteLine("Управление через стрелки <- ->");

NetworkStream stream = client.GetStream();
game.Initialize('X', true);
await GameLoop(stream);

async Task GameLoop(NetworkStream stream)
{
    int row = 0, col = 0;
    while (!game.IsOver)
    {
        Console.Clear();
        game.PrintBoard(row, col);

        if (game.IsMyTurn)
        {
            ConsoleKey key;
            do
            {
                key = Console.ReadKey(true).Key;
                switch (key)
                {
                    case ConsoleKey.UpArrow: if (row > 0) row--; break;
                    case ConsoleKey.DownArrow: if (row < 2) row++; break;
                    case ConsoleKey.LeftArrow: if (col > 0) col--; break;
                    case ConsoleKey.RightArrow: if (col < 2) col++; break;
                }
                Console.Clear();
                game.PrintBoard(row, col);
            } while (key != ConsoleKey.Enter);

            if (game.MakeMove(row, col))
            {
                var json = JsonSerializer.Serialize(new Move(row, col));
                byte[] data = Encoding.UTF8.GetBytes(json + "\n");
                await stream.WriteAsync(data);
                game.SwitchTurn();
            }
        }
        else
        {
            using var reader = new StreamReader(stream, Encoding.UTF8, false, 1024, true);
            string? json = await reader.ReadLineAsync();
            if (json == null) break;
            Move move = JsonSerializer.Deserialize<Move>(json);
            game.MakeMove(move.Row, move.Col);
            game.SwitchTurn();
        }
        game.CheckGameState();
    }
    Console.Clear();
    game.PrintBoard();
    Console.WriteLine("Игра окончена! " + (game.Winner != ' ' ? $"Победил: {game.Winner}" : "Ничья"));
}

record Move(int Row, int Col);

class Game
{
    public char[,] Board = new char[3, 3];
    public char MySymbol;
    public char EnemySymbol;
    public bool IsMyTurn;
    public bool IsOver;
    public char Winner;

    public void Initialize(char mySymbol, bool startFirst)
    {
        MySymbol = mySymbol;
        EnemySymbol = mySymbol == 'X' ? 'O' : 'X';
        IsMyTurn = startFirst;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                Board[i, j] = ' ';
    }

    public void PrintBoard(int highlightRow = -1, int highlightCol = -1)
    {
        Console.WriteLine("Управление через стрелки <- ->");

        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine(" --- --- ---");
            for (int j = 0; j < 3; j++)
            {
                if (i == highlightRow && j == highlightCol)
                {
                    Console.BackgroundColor = ConsoleColor.DarkGray;
                    Console.ForegroundColor = ConsoleColor.Yellow;
                }
                Console.Write($"| {Board[i, j]} ");
                Console.ResetColor();
            }
            Console.WriteLine("|");
        }
        Console.WriteLine(" --- --- ---");
    }

    public bool MakeMove(int row, int col)
    {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || Board[row, col] != ' ')
            return false;

        Board[row, col] = IsMyTurn ? MySymbol : EnemySymbol;
        return true;
    }

    public void SwitchTurn() => IsMyTurn = !IsMyTurn;

    public void CheckGameState()
    {
        for (int i = 0; i < 3; i++)
        {
            if (Board[i, 0] != ' ' && Board[i, 0] == Board[i, 1] && Board[i, 1] == Board[i, 2]) { Winner = Board[i, 0]; IsOver = true; return; }
            if (Board[0, i] != ' ' && Board[0, i] == Board[1, i] && Board[1, i] == Board[2, i]) { Winner = Board[0, i]; IsOver = true; return; }
        }
        if (Board[0, 0] != ' ' && Board[0, 0] == Board[1, 1] && Board[1, 1] == Board[2, 2]) { Winner = Board[0, 0]; IsOver = true; return; }
        if (Board[0, 2] != ' ' && Board[0, 2] == Board[1, 1] && Board[1, 1] == Board[2, 0]) { Winner = Board[0, 2]; IsOver = true; return; }

        bool draw = true;
        foreach (var c in Board)
            if (c == ' ') draw = false;

        if (draw) IsOver = true;
    }
}
