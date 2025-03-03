using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity2
{
    public class Employee
    {
        public int EmployeeId { get; set; }
        public string Name { get; set; }

        public ICollection<Sale> Sales { get; set; }
    }

}
