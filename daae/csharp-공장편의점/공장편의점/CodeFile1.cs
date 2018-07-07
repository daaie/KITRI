using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;
namespace ConsoleApplication1
{
    class DBConnect
    {
        public OleDbConnection conn(string id, string pwd, string ds)
        {

            string sql = string.Format("Provider=MSDAORA.1;Password={0};User ID={1};Data Source={2};Persist Security Info=True",
            pwd, id, ds);     //oracle 서버 연결

            OleDbConnection conn = new OleDbConnection(sql);
            return conn;
        }
    }
    //DTO, VO
    public class Product
    {
        private int num;
        private string name;
        private int price;
        private int quantity;

        public Product() { }
        public Product(int num, string name, int price, int quantity)
        {
            this.num = num;
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }
        public int Num
        {
            get
            {
                return num;
            }
            set
            {
                num = value;
            }
        }
        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public int Price
        {
            get
            {
                return price;
            }
            set
            {
                price = value;
            }
        }
        public int Quantity
        {
            get
            {
                return quantity;
            }
            set
            {
                quantity = value;
            }
        }
        public override string ToString()
        {
            return string.Format("상품 번호 : {0,-5:000}| 상품 이름 : {1} | 가격 : {2,-5} | 수량 : {3,-4} ", num, name, price, quantity);
        }
    }
    //DAO
    public interface PDao
    {
        void insert(Product p);
        List<Product> selectAll();
        Product selectByNum(int num);
        Product selectByName(string name);
        void edit(Product p);
        void del(int num);
    }
    public class ProductDao : PDao
    {
        private DBConnect db;
        private OleDbConnection conn;

        public ProductDao()
        {
            db = new DBConnect();
            conn = db.conn("hr", "hr", "xe");
        }

        public void insert(Product p)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("insert into product values(seq_product.nextval, '{0}', {1}, {2})", p.Name, p.Price, p.Quantity);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("add product exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }

        public List<Product> selectAll()
        {
            List<Product> list = new List<Product>();
            string sql;
            try
            {
                conn.Open();
                sql = "select * from product order by num";
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                while (read.Read())
                {
                    int num = Convert.ToInt32(read.GetValue(0));
                    int price = Convert.ToInt32(read.GetValue(2));
                    int q = Convert.ToInt32(read.GetValue(3));
                    list.Add(new Product(num, read.GetString(1), price, q));

                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();       //데이터베이스 연결 해제
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
            return list;
        }

        public Product selectByNum(int num)
        {
            Product p = null;
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("select * from product where num={0}", num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                if (read.Read())
                {
                    // int num = Convert.ToInt32(read.GetValue(0));
                    int price = Convert.ToInt32(read.GetValue(2));
                    int q = Convert.ToInt32(read.GetValue(3));
                    p = new Product(num, read.GetString(1), price, q);

                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();       //데이터베이스 연결 해제
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
            return p;
        }

        public Product selectByName(string name)
        {
            Product p = null;
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("select * from product where name='{0}'", name);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                if (read.Read())
                {
                    int num = Convert.ToInt32(read.GetValue(0));
                    int price = Convert.ToInt32(read.GetValue(2));
                    int q = Convert.ToInt32(read.GetValue(3));
                    p = new Product(num, read.GetString(1), price, q);

                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();       //데이터베이스 연결 해제
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
            return p;
        }

        public void edit(Product p)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("update product set name = '{0}',price={1}, quantity={2} where num={3}",p.Name, p.Price, p.Quantity, p.Num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("edit product exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }

        public void del(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("delete product where num={0} ", num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("delete product exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }
    }
    public interface ProductService
    {
        bool makeOrder();
        void addProduct(Product p);
        List<Product> searchAll();
        Product searchByNum(int num);
        Product searchByName(string name);
        void editProduct(Product p);
        void delProduct(int num);
    }

    public class UIServiceProd : ProductService
    {
        #region ProductService 멤버
        PDao pd ;
        ODao od = new OrderDao();
        public UIServiceProd(PDao pd)
        {
            this.pd = pd;
        }

        public bool makeOrder()
        {
            int i;
            List<Order> list = od.selectByResult("n");
            foreach (Order o in list)
            {
                Console.WriteLine(o);
            }
            for (i = 0; i < list.Count; i++)
            {
                Order o = list[i];
                Product p = pd.selectByNum(o.ProNum);
                if (o.Quantity <= p.Quantity)
                {
                    pd.edit(new Product(p.Num, p.Name, p.Price, p.Quantity - o.Quantity));
                    od.editResult(o.Num);
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        
        public void addProduct(Product p)
        {
            pd.insert(p);
        }

        public List<Product> searchAll()
        {
            return pd.selectAll(); ;
        }

        public Product searchByNum(int num)
        {
            return pd.selectByNum(num);
        }

        public Product searchByName(string name)
        {
            return pd.selectByName(name);
        }

        public void editProduct(Product p)
        {
            pd.edit(p);
        }

        public void delProduct(int num)
        {
            pd.del(num);
        }

        #endregion
    }
    public class Order
    {
        private int num;
        private int proNum;
        private int quantity;
        private string result;
        private string proName;
        private int proPrice;
        private int totalPrice;

        public Order() { }
        public Order(int num, int proNum, int quantity, string result,
            string proName, int proPrice, int totalPrice)
        {
            this.num = num;
            this.proNum = proNum;
            this.quantity = quantity;
            this.result = result;
            this.proName = proName;
            this.proPrice = proPrice;
            this.totalPrice = totalPrice;
        }
        public int Num
        {
            get
            {
                return num;
            }
            set
            {
                num = value;
            }
        }
        public int ProNum
        {
            get
            {
                return proNum;
            }
            set
            {
                proNum = value;
            }
        }
        public int Quantity
        {
            get
            {
                return quantity;
            }
            set
            {
                quantity = value;
            }
        }
        public string Result
        {
            get
            {
                return result;
            }
            set
            {
                result = value;
            }
        }
        public string ProName
        {
            get
            {
                return proName;
            }
            set
            {
                proName = value;
            }
        }
        public int ProPrice
        {
            get
            {
                return proPrice;
            }
            set
            {
                proPrice = value;
            }
        }
        public int TotalPrice
        {
            get
            {
                return totalPrice;
            }
            set
            {
                totalPrice = value;
            }
        }
        public override string ToString()
        {
            return ProName;
            //"num:" + num + ", proNum:" + proNum + ", quantity:" + quantity +
            //", result:" + result + ", proName:" + ProName + ", proPrice:" +
            // ProPrice + ", totalPrice:" + TotalPrice;
        }
    }
    public interface ODao
    {
        void insert(Order o);
        List<Order> selectAll();
        List<Order> selectByResult(string result);
        void editResult(int num);
        void delete(int num);
    }
    public class OrderDao : ODao
    {
        private DBConnect db;
        private OleDbConnection conn;

        public OrderDao()
        {
            db = new DBConnect();
            conn = db.conn("hr", "hr", "xe");
        }

        public void insert(Order o)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("insert into my_order(num, pro_num, quantity, totalprice) values(seq_my_order.nextval, {0}, {1}, {2})", o.ProNum, o.Quantity, o.TotalPrice);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("add order exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }

        public List<Order> selectAll()
        {
            List<Order> list = new List<Order>();
            string sql;
            try
            {
                conn.Open();
                sql = "select o.num, o.pro_num, o.quantity, o.result, p.name, p.price, o.totalprice from my_order o, product p where o.pro_num=p.num order by o.num";
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                while (read.Read())
                {

                    list.Add(new Order(Convert.ToInt32(read.GetValue(0)),
                        Convert.ToInt32(read.GetValue(1)),
                        Convert.ToInt32(read.GetValue(2)),
                        read.GetString(3), read.GetString(4),
                        Convert.ToInt32(read.GetValue(5)),
                        Convert.ToInt32(read.GetValue(6))));

                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();       //데이터베이스 연결 해제
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
            return list;
        }

        public List<Order> selectByResult(string result)
        {
            List<Order> list = new List<Order>();
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("select * from my_order where result='{0}'", result);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                while (read.Read())
                {
                    Order o = new Order();
                    o.Num = Convert.ToInt32(read.GetValue(0));
                    o.ProNum = Convert.ToInt32(read.GetValue(1));
                    o.Quantity = Convert.ToInt32(read.GetValue(2));
                    o.Result = read.GetString(3);
                    o.TotalPrice = Convert.ToInt32(read.GetValue(4));
                    list.Add(o);

                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();       //데이터베이스 연결 해제
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
            return list;
        }
        public void editResult(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("update my_order set result='y' where num={0}", num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("edit result exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }
        public void delete(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("delete my_order where num={0} and result='n'", num);//and result='n'
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("del order exception");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
                MessageBox.Show("이미 주문이 완료되었습니다 바부야");
            }
            finally
            {
                if (conn != null)
                {
                    conn.Close();
                    Console.WriteLine("데이터베이스 연결 해제..");
                }
            }
        }
    }
    public interface OService
    {
        void addOrder(Order o);
        List<Order> OrderList();
        void delOrder(int num);
    }
    public class OrderService : OService
    {
        private PDao pd;
        private ODao od;

        public OrderService(PDao pd, ODao od)
        {
            this.pd = pd;
            this.od = od;
        }
        public void addOrder(Order o)
        {
            od.insert(o);
        }
        public List<Order> OrderList()
        {
            return od.selectAll();
        }
        public void delOrder(int num)
        {
            od.delete(num);
        }

    }
}
