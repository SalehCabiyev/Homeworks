using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity1
{
    public class Dealer
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public string Location { get; set; }
       
         public virtual List<Car> Cars { get; set; }
    }
}
