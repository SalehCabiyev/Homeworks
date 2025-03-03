using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity2
{
    public class Sale
    {
        public int SaleId { get; set; }
        public DateTime Date { get; set; }

        public int CarId { get; set; }
        public Car Car { get; set; }

        public int CustomerId { get; set; }
        public Customer Customer { get; set; }

        public int EmployeeId { get; set; }
        public Employee Employee { get; set; }
    }

}
