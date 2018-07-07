using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Threading;

namespace newclient
{
    class Echoclient
    {
        private TcpClient client;
        private NetworkStream stream;

        public Echoclient(string serverIp, int port)
        {
            client = new TcpClient();
            client.Connect(serverIp, port);
            stream = client.GetStream();
        }
        public void write()
        {
            byte[] buffer = new byte[255];
            string str = "";
            while (true)
            {
                Console.WriteLine("�޽��� �Է� : ");
                str = Console.ReadLine();

                buffer = Encoding.Unicode.GetBytes(str);
                stream.Write(buffer, 0, buffer.Length);
                stream.Flush();
                if (str == "stop")  //str�� ����Ʈ�� �ٲ۰Ŷ� �����Ⱚ�� ������ �־ contains���..
                {
                    break;
                }
            }
        }
        public void read()
        {
            byte[] buffer = new byte[255];
            string str = "";
            int bytes = 0;
            while (true)
            {
               // Array.Clear(buffer, 0, buffer.Length);
                //str = "";
               // stream.Flush();
                bytes = stream.Read(buffer, 0, buffer.Length);
                str = Encoding.Unicode.GetString(buffer, 0, bytes);
                Console.WriteLine("server : {0} ", str);
                stream.Flush();
                if (str.Contains("stop"))  //str�� ����Ʈ�� �ٲ۰Ŷ� �����Ⱚ�� ������ �־ contains���..
                {
                    break;
                }
            }
        }
        public void start()
        {
            Thread t1 = new Thread(new ThreadStart(write));
            Thread t2 = new Thread(new ThreadStart(read));
            t1.Start();
            t2.Start();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Echoclient ec = new Echoclient("192.168.18.20", 4444);
            ec.start();
        }
    }
}
