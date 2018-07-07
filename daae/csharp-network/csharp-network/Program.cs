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
            Console.WriteLine("Client"+cliNum+" 접속");
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
                //버퍼를 비우는것..강제로 출력해줌
                // listener.Stop();
                
            }
            client.Close();
            Console.WriteLine("Client" + cliNum + " 종료");
        }

        static void Main(string[] args)
        {
            IPAddress addr = IPAddress.Parse("192.168.18.20");
            //0이면 현재 호스트 아이피 
            try 
            {
                listener = new TcpListener(addr, 4444);
                //소켓을 여는 것(서버)
                listener.Start();
                Console.WriteLine("server 시작");
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
