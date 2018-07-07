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
                //������ ���� ��(����)
                string serverIp="192.168.18.20";
                client.Connect(serverIp, 4444);
                NetworkStream stream = client.GetStream();
                while (flag)
                {
                    Console.WriteLine("�޽��� �Է�");
                    string str = Console.ReadLine();
                    if(str=="stop")
                    {
                        flag = false;
                    }

                    buffer = Encoding.Unicode.GetBytes(str);
                    stream.Write(buffer, 0,buffer.Length);
                    //������� ���� �������
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
