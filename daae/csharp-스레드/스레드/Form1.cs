using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace 스레드
{
    public partial class Form1 : Form
    {
        public int farmer = 0;
        public int harvest = 0;
        public bool flag = false;
        public Graphics g;
        public Image image = Image.FromFile("test.jpg");

        public Form1()
        {
            InitializeComponent();
            for (int i = 0; i < 3; i++)
            {
                employ();
            }
            //pictureBox1.Paint += new PaintEventHandler(Demonstrate);
            //pictureBox2.Paint += new PaintEventHandler(Demonstrate);
        }
        public void employ()
        {
            Thread farm = new Thread(new ThreadStart(farming));
            farm.Start();
            farmer++;
            textBox2.Text = Convert.ToString(farmer);
            pictureBox1.Image = image;
        }
        public void farming()
        {
            while (true)
            {
                if (flag)
                {
                    break;
                }
                lock (this)
                {
                    harvest += 5;
                    textBox1.Text = Convert.ToString(harvest);
                }
                Delay(300);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            lock (this)
            {
                if (harvest >= 50)
                {
                    harvest -= 50;
                    employ();
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            flag = true;
        }

        private static DateTime Delay(int MS)
        {
            DateTime ThisMoment = DateTime.Now;
            TimeSpan duration = new TimeSpan(0, 0, 0, 0, MS);
            DateTime AfterWards = ThisMoment.Add(duration);
            while (AfterWards >= ThisMoment)
            {
                System.Windows.Forms.Application.DoEvents();
                ThisMoment = DateTime.Now;
            }
            return DateTime.Now;
        }

    }
}