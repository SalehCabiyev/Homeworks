using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp12
{
    public class Car
    {
        public Guid Id { get; set; } = Guid.NewGuid(); // уникальный идентификатор
        public string Make { get; set; }
        public string Model { get; set; }
        public DateTime Year { get; set; }
    }
}
