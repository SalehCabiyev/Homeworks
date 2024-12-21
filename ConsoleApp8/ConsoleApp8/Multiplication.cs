using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    internal class Multiplication:ICalculatorOperation
    {
        public string Name => "Multiplication";
        public double Execute(double a, double b)
        {
            return a * b;
        }


    }
}
