using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WindowsApplication2
{
    public partial class Form1 : Form //form을 상속받음
    {
        public Form1()
        {
            InitializeComponent();
            listBox1.Items.Add("aaa");
            listBox1.Items.Add("bbb");
            listBox1.Items.Add("ccc");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           // textBox1.Text = (string)listBox1.SelectedItem;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            //string str = textBox1.Text;
            //MessageBox.Show("입력 : " + str);

            int idx;
            idx = listBox1.SelectedIndex;
            listBox1.Items.Remove(listBox1.SelectedItem);
            listBox1.Items.Insert(idx, textBox1.Text);

        }
        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Remove(listBox1.SelectedItem);
        }
    }
}