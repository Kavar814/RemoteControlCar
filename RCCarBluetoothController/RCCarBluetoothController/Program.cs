using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RCCarBluetoothController
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("BT RC Controller v.1.0 by Kavin Govindarajan");
            string input;
            SerialPort serialPort = new SerialPort();
            serialPort.BaudRate = 9600;
            serialPort.PortName = "COM8";
            serialPort.Open();
            while (serialPort.IsOpen)
            {
                input = Convert.ToString(Console.ReadLine());
                serialPort.Write(input);
            }
            Console.ReadKey();
        }
    }
}
