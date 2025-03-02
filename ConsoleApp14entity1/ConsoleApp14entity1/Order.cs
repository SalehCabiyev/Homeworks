using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity1
{
    public class Order
    {
        public int Id { get; set; }
        public string Description { get; set; }
        public Car Car { get; set; }
        public Customer Customer { get; set; }
    }
}
