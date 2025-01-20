using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp12
{
    public class Showroom
    {
        public Guid Id { get; set; } = Guid.NewGuid(); // Идентификатор салона
        public string Name { get; set; }
        public List<Car> Cars { get; set; } = new List<Car>();
        public int CarCapacity { get; set; }
        public int CarCount => Cars.Count;
        public int SalesCount { get; set; }
    }
}
