using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp8
{
    public class Addition:ICalculatorOperation
    {
        public double Execute(double a, double b) 
        {
            return a + b;
        }
        public string Name => "Addition";

    }
}
