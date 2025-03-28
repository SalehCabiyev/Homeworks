using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System;
using System.Net.Http;
using System.Threading;
using System.Threading.Tasks;
using System.Text.Json;



namespace Weatherapp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private const string Apikey = "2f702e993ff233af0858486a46fcc8e0";
        private const string BaseUrl = "https://api.openweathermap.org/data/2.5/weather";
        private Timer _timer;
        private bool _isTimerRunning = false;


        public MainWindow()
        {
            InitializeComponent();
        }


        private async void OnGetWeatherClick(object sender, RoutedEventArgs e)
        {

            string city=CityTextBox.Text;
            if (string.IsNullOrEmpty(city))
            {
                ErrorLabel.Content = "Введите название города.";
                return;
            }
            ErrorLabel.Content = "";
            await GetWeatherAsync(city);
            if (!_isTimerRunning)
            {
                StartPeriodicUpdates(city);
            }
        }
        private async Task GetWeatherAsync(string city)
        {
            try
            {
                using (HttpClient client = new HttpClient())
                {
                    string url = $"{BaseUrl}?q={city}&appid={Apikey}&units=metric&lang=ru";
                    HttpResponseMessage response = await client.GetAsync(url);
                    if (response.IsSuccessStatusCode)
                    {
                        string result = await response.Content.ReadAsStringAsync();
                        Console.WriteLine(result);
                        System.Diagnostics.Debug.WriteLine(result);
                        var options = new JsonSerializerOptions
                        {
                            PropertyNameCaseInsensitive = true
                        };
                        var weatherData = JsonSerializer.Deserialize<WeatherResponse>(result,options);
                        if (weatherData != null && weatherData.Main!=null && weatherData.Weather!=null && weatherData.Weather.Length>0)
                        {
                            Dispatcher.Invoke(() =>
                            {
                                WeatherLabel.Content = $"Погода в {city}: {weatherData.Main.Temp} C\n {weatherData.Weather[0].Description} ";
                            });
                        }
                        
                    }
                    else
                    {
                        Dispatcher.Invoke(() =>
                        {
                            ErrorLabel.Content = "Ошибка при получении данных. Попробуйте снова.";
                        });

                    }
                }
            }
            catch (Exception ex)
            {
                Dispatcher.Invoke(() =>
                {
                    ErrorLabel.Content= $"Ошибка: {ex.Message}";

                });
            }
        }
        private void StartPeriodicUpdates(string city)
        {
            _timer = new Timer(async _ =>
            {
                await GetWeatherAsync(city);
            }, null, TimeSpan.Zero, TimeSpan.FromSeconds(10));  
            _isTimerRunning = true;
        }

        private void StopPeriodicUpdates()
        {
            _timer?.Dispose();
            _isTimerRunning = false;
        }
    }
}