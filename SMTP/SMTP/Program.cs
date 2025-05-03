using System.Net;
using System.Net.Mail;
using Microsoft.Extensions.Configuration;

var configBuilder = new ConfigurationBuilder();
configBuilder.AddJsonFile("appsettings.json", optional: false, reloadOnChange: true);
var config= configBuilder.Build();
var smtpHost = config["Smtp:Host"];
var smtpPort = config["Smtp:Port"];
var smtpUser = config["Smtp:Username"];
var smtpPassword = config["Smtp:Password"];
Console.WriteLine("Enter your message");
var messageText=Console.ReadLine();
Console.WriteLine("Enter recepient email");
var recepientEmail=Console.ReadLine();
using var mailMessage = new MailMessage()
{
    From = new MailAddress("saleh.cabiyev.a@icloud.com"),
    Subject = "Test message",
    Body = messageText,
    IsBodyHtml = false,
};
mailMessage.To.Add(new MailAddress(recepientEmail));
using var smtpClient = new SmtpClient(smtpHost, int.Parse(smtpPort))
{
    Credentials = new NetworkCredential(smtpUser, smtpPassword),
    EnableSsl = true,
};
try
{
    smtpClient.Send(mailMessage);
    Console.WriteLine("email sent successfully.");

}
catch (SmtpException ex)
{
    Console.WriteLine("SMTP ошибка: " + ex.Message);
    Console.WriteLine("Внутренняя ошибка: " + ex.InnerException?.Message);
}