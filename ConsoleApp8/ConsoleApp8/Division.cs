using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    public class Division:ICalculatorOperation
    {
        public string Name => "Division";
        public double Execute(double a, double b)
        {
           if(b== 0)
            {
                throw new DivideByZeroException("Невозможно делить на ноль.");
            }

            return a / b;


        }
    }
}
