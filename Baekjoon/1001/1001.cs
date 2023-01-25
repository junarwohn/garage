using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int input_A = 0;
            int input_B = 0;
            string input;
            string[] line = new string[2];
            input = Console.ReadLine();
            bool result = true;

            result = int.TryParse(input, out input_A);
            if (result)
            {
                input = Console.ReadLine();
                input_B = int.Parse(input);
                Console.WriteLine("{0}", input_A - input_B);
            } else {
                line = input.Split();

                input_A = int.Parse(line[0]);
                input_B = int.Parse(line[1]);


                Console.WriteLine("{0}", input_A - input_B);
            }
        }
    }
}
