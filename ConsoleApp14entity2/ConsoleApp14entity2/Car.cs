using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp14entity2
{
    public class Car
    {
        public int Id { get; set; }
        [Required]
        [StringLength(100)]
        public string Model { get; set; }
        [Required]
        [StringLength(100)]
        public string Make { get; set; }
        [Required]
        [Range(1900, 2100)]
        public int Year {  get; set; }
        public decimal Price {  get; set; }
        public ICollection<ServiceHistory> ServiceHistories { get; set; }
        public ICollection<Sale> Sales { get; set; }
    }
}
