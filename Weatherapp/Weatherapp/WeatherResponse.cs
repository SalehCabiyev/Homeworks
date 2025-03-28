using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Weatherapp
{
    public class WeatherResponse
    {
        public Weather[] Weather { get; set; }
        public MainInfo Main { get; set; }
        
    }
}
