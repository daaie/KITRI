using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace 서버프로그램
{
    public class Server
    {
        private Dictionary<int, TcpClient> clientList;
        private Dictionary<int, NetworkStream> streamList;
        private IPAddress addr;
        private TcpListener listener;

        private int cnt;
        private bool flag = true;

        public Server()
        {
            addr = IPAddress.Parse("192.168.18.20");
            listener = new TcpListener(addr, 4444);
            clientList = new Dictionary<int, TcpClient>();
            streamList = new Dictionary<int, NetworkStream>();
        }
      
        public void start()
        {
            listener.Start();
            Console.WriteLine("서버시작");
            while (true)
            {
                TcpClient client = null;
                try
                {
                    client = listener.AcceptTcpClient();
                    Console.WriteLine("{0} : 클라이언트 접속", cnt);
                    byte[] imsi = new byte[500];
                    imsi = Encoding.Unicode.GetBytes(string.Format("\n\n{0}번째 Client 접속\n\n", cnt));
                    foreach (KeyValuePair<int, NetworkStream> s in streamList)
                    {
                        s.Value.Write(imsi, 0, imsi.Length);
                    }
                    clientList.Add(cnt, client);
                    cnt++;
                    Thread t = new Thread(new ThreadStart(myThread));
                    t.Start();
                }
                catch// (System.InvalidOperationException e)
                {
                    // Console.WriteLine(e);
                }
            }
        }
        public void myThread()
        {
            int clinum = cnt - 1;
            int bytes = 0;
            string msg = "";
            byte[] buffer = new byte[500];
            NetworkStream stream = clientList[clinum].GetStream();
            streamList.Add(clinum, stream);
            while (flag)
            {
                try
                {
                    Array.Clear(buffer, 0, buffer.Length);
                    bytes = stream.Read(buffer, 0, buffer.Length);
                    msg = Encoding.Unicode.GetString(buffer, 0, bytes);

                    Console.WriteLine("{0}번째 Client : {1}", clinum, msg);

                    if (msg == "stop")
                    {
                        msg = "";
                        break;
                    }

                    msg = string.Format("{0}번째 클라이언트 : {1}\n", clinum, msg);
                    buffer = Encoding.Unicode.GetBytes(msg);

                    foreach (KeyValuePair<int, NetworkStream> stemp in streamList)
                    {
                        stemp.Value.Write(buffer, 0, buffer.Length);
                    }
                }
                catch
                {

                }
            }
            clientList[clinum].Close();
            streamList[clinum].Close();

            clientList.Remove(clinum);
            streamList.Remove(clinum);

            byte[] imsi = new byte[500];
            imsi = Encoding.Unicode.GetBytes(string.Format("\n{0}번째 Client 나감\n\n", clinum));
            foreach (KeyValuePair<int, NetworkStream> s in streamList)
            {
                s.Value.Write(imsi, 0, imsi.Length);
            }
        }

        public void stop()
        {
            listener.Stop();
        }
        public bool Flag
        {
            get
            {
                return flag;
            }
            set
            {
                flag = value;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Server server = new Server();
            server.start();
            server.stop();
        }
    }
}
