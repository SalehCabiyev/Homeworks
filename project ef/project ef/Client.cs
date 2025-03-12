using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Internal;

namespace project_ef
{
    public class Client
    {
        [Key]
        public int ClientId { get; set; }
        [Required]
        public string FirstName { get; set; }
        [Required]
        public string LastName { get; set; }
        public string Phone { get; set; }
        [Required]
        [MinLength(8)]
        
        public string Password { get; set; }
        [Required]
       
        public string Email { get; set; }
        public ICollection<Car> Cars { get; set; }
        public ICollection<Order> Orders { get; set; } 
    }

   
}
