using System;
using System.Text;
using LidarWrapper;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Wrapper w = new Wrapper();
            byte[] bytes = Encoding.ASCII.GetBytes("com3");
            unsafe
            {
                fixed (byte* p = bytes)
                {
                    sbyte* sp = (sbyte*)p;
                    w.connect(sp, 256000);
                }
            }
            w.startMotor();


            w.startMotor();
            w.DisposeDriver();
        }
    }
}
