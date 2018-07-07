using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;
namespace csharp_network
{
    class Program
    {
        private static TcpListener listener;
        private static int cnt=0;

        public static void waiting()
        {
            TcpClient client = listener.AcceptTcpClient();
            Thread thread = new Thread(delegate()
            {
                server(client);
            });
            thread.Start();
        }

        public static void server(TcpClient client)
        {
            int cliNum = cnt++;
            byte[] buffer = new byte[255];
            int bytes;
            string msg;
            Console.WriteLine("Client"+cliNum+" ����");
            NetworkStream stream = client.GetStream();
            while (true)
            {

                bytes = stream.Read(buffer, 0, buffer.Length);
                msg = Encoding.Unicode.GetString(buffer, 0, bytes);
                if (msg == "stop")
                {
                    break;
                }
                Console.WriteLine("Client{0} : {1}", cliNum, msg);
                stream.Write(buffer, 0, buffer.Length);
                stream.Flush();
                //���۸� ���°�..������ �������
                // listener.Stop();
                
            }
            client.Close();
            Console.WriteLine("Client" + cliNum + " ����");
        }

        static void Main(string[] args)
        {
            IPAddress addr = IPAddress.Parse("192.168.18.20");
            //0�̸� ���� ȣ��Ʈ ������ 
            try 
            {
                listener = new TcpListener(addr, 4444);
                //������ ���� ��(����)
                listener.Start();
                Console.WriteLine("server ����");
                while (true)
                {
                    Thread t_wait = new Thread(new ThreadStart(waiting));
                    t_wait.Start();
                    t_wait.Join();
                }
            }
            catch (System.InvalidOperationException e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
