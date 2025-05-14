using FavoriteMoviesApp.Models;
using QuestPDF.Fluent;
using QuestPDF.Infrastructure;

public class PdfService
{
    public byte[] GenerateFavoriteMoviesPdf(List<Movie> movies)
    {
        QuestPDF.Settings.License = LicenseType.Community;

        var pdf = Document.Create(container =>
        {
            container.Page(page =>
            {
                page.Margin(50);
                page.Content().Column(column =>
                {
                    column.Item().PaddingBottom(25).Text("Избранные фильмы").FontSize(20).Bold().Underline();

                    foreach (var movie in movies)
                    {
                        column.Item().Text($"{movie.Title} ({movie.Year}) - {movie.Genre}");
                    }
                });
            });
        });

        using var stream = new MemoryStream();
        pdf.GeneratePdf(stream);
        return stream.ToArray();
    }
}
