using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity1
{
    public class Customer
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public virtual List<Car> cars { get; set; }
        
    }
}
