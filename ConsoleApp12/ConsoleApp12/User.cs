using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp12
{
    public class User
    {
        public Guid Id { get; set; } = Guid.NewGuid();
        public string Username { get; set; }
        public string Password { get; set; }
        public Guid? ShowroomId { get; set; } // Добавляем связь с салоном через Id
        public string Role { get; set; } // Роль пользователя (например, admin или user)
        public Showroom Showroom { get; set; } // Салон пользователя
    }
}
