// See https://aka.ms/new-console-template for more information
using System;
using System.Collections.Generic;

public class Book
{
    public string Title { get; set; }
    public string Author {  get; set; }
    public uint Year {  get; set; }

    public Book(string title,string author,uint year)
    {
        Title = title;
        Author = author;
        Year = year;

    }
    public  virtual void ToString()
    {
        Console.WriteLine($"Title: {Title}\n Author: {Author}\n Year: {Year}\n");
    }

}
public class Library
{
    List<Book> books;
    public Library()
    {
        books = new List<Book>();
    }
    public void AddBook(Book book)
    {
        books.Add(book);
    }
    public void RemoveBook(int index)
    {
        books.RemoveAt(index);
    }
    public void ShowBooks()
    {
        foreach (Book book in books)
        {
            Console.WriteLine($"index: {books.IndexOf(book)}");
            book.ToString();


        }
    }



    class Program
    {





        static void Main()

        {
            Library library = new Library();

            uint number = 0;
            bool a = true;
            while (a)
            {
                Console.WriteLine("Welcome to the library\n" +
                    "Menu:\n" +
                    "1.Add book\n" +
                    "2.Delete book\n" +
                    "3.Show all books\n" +
                    "4.Exit\n" +
                    "Enter number [1-4]:");

                uint.TryParse(Console.ReadLine(), out number);

                switch (number)
                {
                    case 1:
                        Console.WriteLine("Enter title:");
                        string title = Console.ReadLine();
                        Console.WriteLine("Enter author:");
                        string author = Console.ReadLine();
                        Console.WriteLine("Enter year:");
                        uint year;
                        uint.TryParse(Console.ReadLine(), out year);

                        Book newBook = new Book(title, author, year);
                        library.AddBook(newBook);
                        break;
                    case 2:
                        Console.WriteLine("Enter index:");
                        int index;
                        int.TryParse(Console.ReadLine(), out index);
                        library.RemoveBook(index);
                        Console.WriteLine("The book was successfully deleted");
                        break;

                    case 3:
                        if (library.books.Count == 0) { Console.WriteLine("library is empty"); }
                        library.ShowBooks(); break;
                    case 4:
                        Console.WriteLine("Exiting...");
                        a = false;
                        break;
                    default: Console.WriteLine("Error input"); break;



                }
            }
        }
    }
} 