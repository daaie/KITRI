using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace 버튼이미지
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Bitmap bitmap = new Bitmap(@"\test.jpg");
            //이미지를 메모리에 옮긴게 비트맵

            MyButton ibutton = new MyButton();
            ibutton.Parent = this; //버튼의 부모가 현재 form
            ibutton.Bounds = new Rectangle(10, 150, 128 , 128);
            ibutton.BackImage = bitmap;
            ibutton.Click += new EventHandler(ibutton_click);

        }
        private void ibutton_click(object sender, EventArgs e)
        {
            MessageBox.Show("이미지 버튼 클릭");
        }
    }
}