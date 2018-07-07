using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace server
{
    class EchoServer
    {
        private IPAddress addr;
        private TcpListener listener;
        private List<TcpClient> clientList;
        private int cnt;

        public EchoServer()
        {
            addr = new IPAddress(0);
            listener = new TcpListener(addr, 4444);
            clientList = new List<TcpClient>();
        }
        public void start()
        {
            listener.Start();
            Console.WriteLine("server 矫累");
            while (true)
            {
                TcpClient client = null;
                try
                {
                    client = listener.AcceptTcpClient();
                    Console.WriteLine("Client 立加");
                }
                catch (System.InvalidOperationException e)
                {
                    Console.WriteLine(e);
                }
                clientList.Add(client);
                cnt++;
                Thread t = new Thread(new ThreadStart(myThread));
                t.Start();
            }
        }
        public void myThread()
        {
            int bytes = 0;
            string msg = "";
            byte[] buffer = new byte[255];
            Console.WriteLine("{0}锅掳 Client 立加", cnt - 1);
            NetworkStream stream = clientList[cnt - 1].GetStream();
            while (true)
            {
                bytes = stream.Read(buffer,0,buffer.Length);
                msg = Encoding.Unicode.GetString(buffer, 0, bytes);

                Console.WriteLine("Client : {0}", msg);
                stream.Write(buffer, 0, buffer.Length);
                stream.Flush();
                if (msg == "stop")
                {
                    break;
                }
            }
            clientList[cnt - 1].Close();
        }
        public void stop()
        {
            listener.Stop();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            EchoServer server = new EchoServer();
            server.start();
            server.stop();
        }
    }
}
