using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{
    public interface ICalculatorOperation
    {
        public double Execute(double a, double b) { return 0; }
        public string Name { get; }

    }
}
