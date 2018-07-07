using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using ConsoleApplication1;

namespace 공장편의점
{
    public partial class Form3 : Form
    {
        public OService service;
        public PDao pd;
        public ODao od;
        public Product p;
        private Order otemp;
        public Form3()
        {
            pd = new ProductDao();
            od = new OrderDao();
            service = new OrderService(pd, od);
            InitializeComponent();
            Print_itemlist();
            Print_orderlist();
        }
        public void Print_itemlist()
        {
            listBox1.Items.Clear();
            List<Product> plist = pd.selectAll();
            foreach (Product pl in plist)
            {
                listBox1.Items.Add(pl.Name);
            }
        }
        public void Print_orderlist()
        {
            listBox2.Items.Clear();
            List<Order> olist = service.OrderList();
            foreach (Order ol in olist)
            {
                listBox2.Items.Add(ol);
            }
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            p = pd.selectByName((string)listBox1.SelectedItem);
            textBox1.Text = "";
            textBox2.Text = p.Num + "";
            textBox3.Text = p.Price + "";
            textBox4.Text = p.Quantity + "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)  //주문 버튼
        {
            Order o = new Order();
            o.ProName = (string)listBox1.SelectedItem;
            o.ProNum = Int32.Parse(textBox2.Text);
            o.ProPrice = Int32.Parse(textBox3.Text);
            o.Quantity = Int32.Parse(textBox4.Text);
            o.TotalPrice = o.Quantity * o.ProPrice;
            textBox6.Text = o.TotalPrice + "";

            service.addOrder(o);
            Print_orderlist();

        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            otemp = (Order)listBox2.SelectedItem;
            textBox1.Text = otemp.Num + "";
            textBox2.Text = otemp.ProNum + "";
            textBox3.Text = otemp.ProPrice + "";
            textBox4.Text = otemp.Quantity + "";
            textBox5.Text = otemp.Result;
            textBox6.Text = otemp.TotalPrice + "";
        }

        private void button2_Click(object sender, EventArgs e) //주문취소버튼
        {
            if (otemp != null)
            {
                service.delOrder(otemp.Num);
            }
            Print_orderlist();
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            (new Form2()).ShowDialog();

            this.Close();
        }
    }
}