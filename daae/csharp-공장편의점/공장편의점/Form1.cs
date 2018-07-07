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
    public partial class Form1 : Form
    {
        public ProductService service;
        public Product p;
        public OrderDao od = new OrderDao();
        public Form1()
        {
            InitializeComponent();
            service = new UIServiceProd(new ProductDao());
            print_listBox1();
            print_listBox2();
        }
        private void print_listBox1()
        {
            listBox1.Items.Clear();
            List<Product> list = service.searchAll();
            foreach (Product prod in list)
            {
                listBox1.Items.Add(prod.Name);
            }
        }
        private void print_listBox2()
        {
            listBox2.Items.Clear();
            List<Order> list = od.selectAll();
            foreach (Order o in list)
            {
                listBox2.Items.Add(o.ProName);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            p = new Product();
            p.Name = textBox1.Text;
            p.Price = Int32.Parse(textBox2.Text);
            p.Quantity = Int32.Parse(textBox3.Text);
            service.addProduct(p);
            print_listBox1();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (p != null)
            {
                service.delProduct(p.Num);
                print_listBox1();
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (p != null)
            {
                p.Price = Int32.Parse(textBox2.Text);
                p.Quantity = Int32.Parse(textBox3.Text);
                service.editProduct(p);
            }
        }



        private void listBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            if (e != null)
            {
                p = service.searchByName((string)listBox1.SelectedItem);
                textBox1.Text = p.Name;
                textBox2.Text = p.Price + "";
                textBox3.Text = p.Quantity + "";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Hide();
            (new Form2()).ShowDialog();

            this.Close();
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            List<Order> olist = od.selectAll();
            foreach (Order o in olist)
            {
                if (o.ProName == (string)listBox2.SelectedItem)
                {
                    textBox4.Text = o.Quantity + "";
                    textBox5.Text = o.Result;
                }

            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            bool check=true;
            check = service.makeOrder();
            if (check == false)
            {
                List<Order> list = od.selectByResult("n");
                foreach (Order o in list)
                {
                    Product ptemp = service.searchByNum(o.ProNum);
                    string str = "수량부족으로 " + ptemp.Name + " 주문처리 취소";
                    MessageBox.Show(str);
                }
            }
            print_listBox1();
            print_listBox2();
        }


    }
}