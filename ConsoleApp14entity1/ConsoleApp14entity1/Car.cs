using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace ConsoleApp14entity1
{
    public class Car
    {

        public int Id { get; set; }
        [Required]
        [StringLength(100)]
        
        public string Make { get; set; }
        [Required]
       
        public string Model { get; set; }

        [Range(1900, 2100)]

        public int Year { get; set; }
        public int DealerId { get; set; }
         public virtual Dealer Dealer { get; set; }
        public bool IsDeleted { get; set; } = false;    

    }

}
