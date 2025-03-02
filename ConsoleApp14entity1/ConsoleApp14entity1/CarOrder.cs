using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity1
{
    public class CarOrder
    {
    
        public int Id { get; set; }
        public int CarId { get; set; }
        public virtual Car Car { get; set; }
        public int CustomerId {  get; set; }  
         public virtual Customer Customer { get; set; }


    }
}
