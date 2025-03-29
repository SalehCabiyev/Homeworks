using Lesson11.Data.Model;

namespace Lesson11.Interfaces;

public interface IFileService
{
    // Save
    public void Save(MovieSearchResult result);
    public void Delete();
    public void Load();
    // Delete
}