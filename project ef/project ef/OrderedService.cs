using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace project_ef
{
    public class OrderedService
    {
        public int OrderedServiceId { get; set; }
        public int OrderId { get; set; } 
        public Order Order { get; set; }
        public int ServiceId { get; set; }
        public Service Service { get; set; } 
        public int Quantity { get; set; }
        public decimal TotalPrice => Service.Price * Quantity; 
    }
}
