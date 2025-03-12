using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace project_ef
{
    public class Order
    {
        [Key]
        public int OrderId { get; set; }
        public int ClientId { get; set; } 
        public Client Client { get; set; } 
      
        public DateTime Date { get; set; }

        public string Status { get; set; } 

        public ICollection<OrderedService> OrderedServices { get; set; }
    }
}
