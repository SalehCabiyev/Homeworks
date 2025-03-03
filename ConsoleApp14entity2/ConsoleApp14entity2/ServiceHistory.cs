using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity2
{
    public class ServiceHistory
    {
        public int ServiceHistoryId { get; set; }
        public DateTime ServiceDate { get; set; }
        public string Description { get; set; }

        public int CarId { get; set; }
        public Car Car { get; set; }
    }

}
