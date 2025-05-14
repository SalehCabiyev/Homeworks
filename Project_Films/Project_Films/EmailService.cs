using System.Net.Mail;
using MailKit.Net.Smtp;
using MailKit.Security;
using MimeKit;

namespace FavoriteMoviesApp.Services
{
    public class EmailService
    {
        public async Task SendEmailWithPdfsAsync(string toEmail, List<byte[]> pdfFiles)
        {
            var message = new MimeMessage();
            message.From.Add(MailboxAddress.Parse("saleh.cabiyev.a@icloud.com")); // Укажи реальный email
            message.To.Add(MailboxAddress.Parse(toEmail));
            message.Subject = "Ваши избранные фильмы";

            var bodyBuilder = new BodyBuilder
            {
                HtmlBody = "<h2>Спасибо, что пользуетесь Favorite Movies App!</h2><p>Ваши избранные фильмы — в приложенных PDF-файлах.</p>"
            };

            for (int i = 0; i < pdfFiles.Count; i++)
            {
                bodyBuilder.Attachments.Add($"Favorites_Part_{i + 1}.pdf", pdfFiles[i]);
            }

            message.Body = bodyBuilder.ToMessageBody();

            using var smtp = new MailKit.Net.Smtp.SmtpClient();
            await smtp.ConnectAsync("smtp.mail.me.com", 587, SecureSocketOptions.StartTls); // Укажи SMTP сервер
            await smtp.AuthenticateAsync("saleh.cabiyev.a@icloud.com", "xymf-fksk-dugg-jujd"); // Укажи логин и пароль
            await smtp.SendAsync(message);
            await smtp.DisconnectAsync(true);
        }
    }
}
