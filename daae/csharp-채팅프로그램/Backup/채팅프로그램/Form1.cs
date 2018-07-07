using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using System.IO;
using System.Net.Sockets;

namespace 채팅프로그램 //클라이언트 
{
    public partial class Form1 : Form
    {
        private TcpClient client;
        private NetworkStream stream;
        private string writeline;
        private bool flag=false;

        public Form1()
        {
            InitializeComponent();
            Random rand = new Random();
            textBox2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(rand.Next(200,255))))), ((int)(((byte)rand.Next(200,255)))), ((int)(((byte)rand.Next(200,255)))));
            textBox1.ForeColor = textBox2.ForeColor;
            client = new TcpClient();
            client.Connect("192.168.18.20", 4444);
            stream = client.GetStream();
            Thread t1 = new Thread(new ThreadStart(write));
            Thread t2 = new Thread(new ThreadStart(read));
            t1.Start();
            t2.Start();
        }
        public void write()
        {
            byte[] buffer = new byte[500];
            string str = "";
            while (true)
            {
                while (flag)
                {
                    Array.Clear(buffer, 0, buffer.Length);
                    str = writeline;
                    buffer = Encoding.Unicode.GetBytes(str);
                    stream.Write(buffer, 0, buffer.Length);
                    stream.Flush();
                    flag = false;
                }
            }
        }

        public void read()
        {
            byte[] buffer = new byte[500];
            int bytes = 0;
            string readline;
            while (true)
            {
                Array.Clear(buffer, 0, buffer.Length);
                bytes = stream.Read(buffer, 0, buffer.Length);
                readline = Encoding.Unicode.GetString(buffer, 0, bytes);
                stream.Flush();
                textBox1.AppendText(readline);
            }
        }

        public void stop()
        {
            byte[] buffer = new byte[500];
            Array.Clear(buffer, 0, buffer.Length);
            buffer = Encoding.Unicode.GetBytes("stop");
            stream.Write(buffer, 0, buffer.Length);
            stream.Flush();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            writeline = textBox2.Text;
            flag = true;
            textBox2.Text = "";
            textBox2.Focus();
            textBox2.Select(0,0);
        }

        private void textBox2_KeyPress(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == '\r')
            {
                button1_Click(sender, e);
            }
            SendKeys.Flush();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            stop();
            Application.ExitThread();
            Environment.Exit(0);
        }

    }
}