using  System;
using project_ef;
using Microsoft.EntityFrameworkCore;
public class Program
{
    public static void Main()
    {
       using  var context = new AutoServiceContext();

        context.Database.Migrate();
        var menu = new MenuService();

        var services = new List<Service>
        {
            new Service { Name = "Замена масла", Price = 500 },
            new Service { Name = "Диагностика двигателя", Price = 1500 },
            new Service { Name = "Шиномонтаж", Price = 1000 },
            new Service { Name = "Ремонт тормозной системы", Price = 2000 }
        };

        foreach (var service in services)
        {

            if (!context.Services.Any(s => s.Name == service.Name))
            {

                context.Services.Add(service);
            }
        }





        context.SaveChanges();

        

        menu.HandleMainMenuChoice(context);


    }
}