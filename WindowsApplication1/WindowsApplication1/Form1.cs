using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WindowsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ContextMenuStrip1.Show(button1, new Point(0, button1.Height));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ContextMenuStrip2.Show(button4, new Point(0, button4.Height));
        }




    }
}