using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp12
{
    public class Sale
    {
        public Guid Id { get; set; } = Guid.NewGuid();
        public Showroom Showroom { get; set; } // Ссылка на салон, где произошла продажа
        public Car Car { get; set; } // Проданная машина
        public User User { get; set; } // Пользователь, который продал машину
        public DateTime SaleDate { get; set; }
        public decimal Price { get; set; }
    }
}
