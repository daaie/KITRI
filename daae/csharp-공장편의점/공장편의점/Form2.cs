using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace 공장편의점
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void radioButton1_MouseDown(object sender, MouseEventArgs e)
        {
            this.Hide();//form2가 끝나며 프로그램이 끝나니까 끝내지말고 숨겨놔야함
            (new Form1()).ShowDialog();

            this.Close(); //프로그램 클래스 메인을 닫아줌ㅈ
        }

        private void radioButton2_MouseDown(object sender, MouseEventArgs e)
        {
            this.Hide();
            (new Form3()).ShowDialog();

            this.Close(); 
        }
    }
}