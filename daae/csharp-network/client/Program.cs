using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace client
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] buffer = new byte[255];
            bool flag=true;
            string msg="";
            int bytes=0;
            IPAddress addr = new IPAddress(0);
            try
            {
                TcpClient client = new TcpClient();
                //소켓을 여는 것(서버)
                string serverIp="192.168.18.20";
                client.Connect(serverIp, 4444);
                NetworkStream stream = client.GetStream();
                while (flag)
                {
                    Console.WriteLine("메시지 입력");
                    string str = Console.ReadLine();
                    if(str=="stop")
                    {
                        flag = false;
                    }

                    buffer = Encoding.Unicode.GetBytes(str);
                    stream.Write(buffer, 0,buffer.Length);
                    //여기까진 버퍼 살아잇음
                    stream.Read(buffer, 0, buffer.Length);
                    for (int i = 0; i < buffer.Length; i++)
                    {
                        Console.Write(buffer[i]);
                    }
                    msg = Encoding.Unicode.GetString(buffer, 0, 4);
                    Console.WriteLine("server : {0}", msg);

                }
            }
            catch (System.InvalidOperationException e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
