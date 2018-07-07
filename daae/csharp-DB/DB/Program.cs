using System.Data;
using System.Data.OleDb;
using System;
using System.Collections.Generic;
using System.Text;

namespace DB
{
    class DBConnect
    {
        public OleDbConnection conn(string id, string pwd, string ds)
        {
            string sql = string.Format("Provider=MSDAORA.1;Password={0};User ID={1};Data Source={2};Persist Security Into=true"
                , pwd, id, ds);
            OleDbConnection conn = new OleDbConnection(sql);
            return conn;
        }
    }
    //프로덕트처럼 관련있는 정보를 묶어주는 클래스는 보통
    //DTO -> 데이타 트랜스퍼 오브젝트
    //VO -> 밸류 오브젝트
    class Order
    {
        private int num;
        private int pro_num;
        private int quantity;
        private string result;
        private string proName;
        private int proPrice;
        private int totalPrice;

        public Order() { }
        public Order(int num, int pro_num, int quantity, string result, string proName, int proPrice, int totalPrice)
        {
            this.num = num;
            this.pro_num = pro_num;
            this.quantity = quantity;
            this.result = result;
            this.proName = proName;
            this.proPrice = proPrice;
            this.totalPrice=totalPrice;
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
        public int Pro_num
        {
            get
            {
                return pro_num;
            }
            set
            {
                pro_num = value;
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
                totalPrice= value;
            }
        }
        public override string ToString() 
        {
            return "\n주문번호 : " + num + ", 제품 번호:" + pro_num + ", 주문 수량:" + quantity + ", 결과 :" + result
                + "\n제품이름 :" + proName + ", 제품가격 :" + proPrice + ", 총 가격 :" + totalPrice;
        }

    }
    class Product
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
        public override string ToString()  //객체를 출력하면 투스트링 자동으로 호출됨 원래는 클래스 타입이 출력 일케 지정하면 값출ㄺ
        //부모의 버츄얼을 재정의할때 쓰는 키워드가 override
        //버츄얼안하고 바꾸면 컴파일 과정에서..버추얼은 런타임 과정에서 바뀜..
        {
            return "num:" + num + ", name:" + name + ",price:" + price + ",quantity:" + quantity;
        }

    }
    interface ProductDao
    {
        void insert(Product p);
        List<Product> selectAll();
        Product selectByNum(int num);
        Product selectByName(String name);
        void edit(Product p);
        void del(int num);
        void DBClose();
        void ArrList();
    }
    interface OrderDao
    {
        void insert(Order or);
        List<Order> selectAll();
        List<Order> selectResult(string result);
        void editResult(int num);
        void del(int num);
        void DBClose();
    }
    //디비처리만 전담하는 클래스는 보통
    //DAO -> 데이타 베이스 엑세스 오브젝트
    //서비스 클래스도 있는데 얘는 기능을 제공하는 클래스 -> DAO를 끌어다씀
    //요샌 보통 서비스디에이오로 묶어서 클래스만듬
    class OracleProductDao : ProductDao
    {
        private DBConnect db; //디비 커넥트 객체
        private OleDbConnection conn;

        public OracleProductDao()
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
                //sql = "insert into product values(seq_product.nextval,"+p.Name+","+p.Price+","+p.Quantity+")";
                sql = string.Format("insert into product values(seq_product.nextval,'{0}',{1},{2})", p.Name, p.Price, p.Quantity);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("인설트 예외발생");
                }
                Console.WriteLine(idx);
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생 : {0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
        }
        public List<Product> selectAll()
        {
            List<Product> list = new List<Product>();
            //list는 collection...가변 배열
            //stl standart template library
            //object 는 어떤 형태든 저장가능함 ..
            //upcasting 하면 부모행세를함..부모멤버변수형태씀 오버라이딩된거만 자식걸 실행함

            string sql;
            try
            {
                conn.Open();
                sql = "select * from product order by num";
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();

                while (read.Read())
                {
                    list.Add(new Product(Convert.ToInt32(read.GetValue(0)), read.GetString(1), Convert.ToInt32(read.GetValue(2)), Convert.ToInt32(read.GetValue(3))));
                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
            return list;
        }
        public Product selectByNum(int num)
        {
            //List<Product> list;
            //list = selectAll();
            //foreach (Product p in list)
            //{
            //    if (p.Num == num)
            //    {
            //        return p;
            //    }
            //}
            Product p = null;
            string sql;
            try
            {
               
                conn.Open();
                sql = "select * from product where num=" + num;
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();

                while (read.Read())
                {
                    p = new Product(Convert.ToInt32(read.GetValue(0)), read.GetString(1), Convert.ToInt32(read.GetValue(2)), Convert.ToInt32(read.GetValue(3)));
                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
            return p;
        }
        public Product selectByName(String name)
        {
            //List<Product> list;
            //list = selectAll();
            //foreach (Product p in list)
            //{
            //    if (p.Name == name)
            //    {
            //        return p;
            //    }
            //}
            //return null;
            Product p = null;
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("select * from product where name='{0}'", name);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();

                while (read.Read())
                {
                    p = new Product(Convert.ToInt32(read.GetValue(0)),
                        read.GetString(1), Convert.ToInt32(read.GetValue(2)), Convert.ToInt32(read.GetValue(3)));
                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
            return p;
        }

        public void edit(Product p)
        {
            string sql;
            try
            {
                conn.Open();

                sql = string.Format("update product set name='{0}',price={1},quantity={2} where num={3}", p.Name, p.Price, p.Quantity, p.Num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception("수정할게없어");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
        }

        public void del(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = "delete from product where num=" + num;
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 삭제할 게 없어");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
        }
        public void ArrList()
        {
            string sql;
            int idx;
            OleDbCommand cmd;
            try
            {
                conn.Open();
                sql = "drop sequence seq_product";
                cmd = new OleDbCommand(sql, conn);
                idx = cmd.ExecuteNonQuery();

                sql = "create sequence seq_product";
                //cmd.CommandText(sql);
                cmd = new OleDbCommand(sql, conn);
                idx = cmd.ExecuteNonQuery();

                sql = "update product set num=seq_product.nextval";
                cmd.CommandText=sql;
               // cmd = new OleDbCommand(sql, conn);
                idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                     throw new Exception(" 시퀀스업데이트에러");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
        }
        public void DBClose()
        {
            if (conn != null)
            {
                conn.Close();
                Console.WriteLine("\n데이터베이스연결해제\n");
            }
        }
    }
    class OracleOrderDao : OrderDao
      
    {
        private DBConnect db; //디비 커넥트 객체
        private OleDbConnection conn;

        public OracleOrderDao()
        {
            db = new DBConnect();
            conn = db.conn("hr", "hr", "xe");
        }
        public void insert(Order or)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("insert into my_order(num,pro_num,quantity,totalprice) values(seq_my_order.nextval,{0},{1},{2})", or.Pro_num, or.Quantity, or.TotalPrice);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 주문 추가 예외발생");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생 : {0}", ex.Message);
            }
            finally
            {
                DBClose();
            }

        }
        public List<Order> selectAll()
        {
            List<Order> list = new List<Order>();
            string sql;
            try
            {
                conn.Open();
                sql = "select o.num, o.pro_num, o.quantity, o.result,p.name,p.price,o.totalprice from my_order o, product p where o.pro_num=p.num order by o.num";
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();

                while (read.Read())
                {
                    list.Add(new Order(Convert.ToInt32(read.GetValue(0)), Convert.ToInt32(read.GetValue(1)),
                        Convert.ToInt32(read.GetValue(2)), read.GetString(3), read.GetString(4),
                        Convert.ToInt32(read.GetValue(5)), Convert.ToInt32(read.GetValue(6))));
                }
                read.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
            return list;
        }
        public List<Order> selectResult(string result)
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
                    o.Pro_num = Convert.ToInt32(read.GetValue(1));
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
                DBClose();
            }
            return list;
        }
        public void editResult(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = "update my_order set result='y' where num=" + num;
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 삭제할 게 없어");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }

        }
        public void del(int num)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("delete from my_order where num={0} and result ='n'" , num);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 삭제할 게 없어");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("에러발생{0}", ex.Message);
            }
            finally
            {
                DBClose();
            }
        }

        public void DBClose()
        {
            if (conn != null)
            {
                conn.Close();
                Console.WriteLine("\n데이터베이스연결해제\n");
            }
        }
    }

    interface ProductService
    {
        void makeOrder();
        void addProduct();
        void searchAll();
        void searchByNum();
        Product searchByName();
        void editProduct();
        void delProduct();
        void List_Writeinfo(List<Product> list);
        void Product_Writeinfo(Product p);
        void AranList();
    }

    class ConsolServiceProd : ProductService
    {
        private OrderDao od;
        private ProductDao pd;
        public ConsolServiceProd(OrderDao od, ProductDao pd)
        {
            this.pd = pd;
            this.od = od;
        }
        public void makeOrder()
        {
            List<Order> list = od.selectResult("n");
            foreach (Order o in list)
            {
                Console.WriteLine(o);
            }
            for (int i=0;i<list.Count;i++)
            {
                Order o = list[i];
                Product p = pd.selectByNum(o.Pro_num);
                if(o.Quantity<=p.Quantity)
                {
                    pd.edit(new Product(p.Num,p.Name,p.Price,p.Quantity-o.Quantity));
                    od.editResult(o.Num);
                    Console.WriteLine("출고되었습니다");
                }
                else 
                {
                    Console.WriteLine("수량이 부족하당..");
                }
            }
        }
        public void addProduct()
        {
            Product p = new Product();
            Console.WriteLine("제품명을 입력해");
            p.Name = Console.ReadLine();
            Console.WriteLine("가격을 입력해");
            p.Price = Int32.Parse(Console.ReadLine());
            Console.WriteLine("수량을 입력해");
            p.Quantity = Int32.Parse(Console.ReadLine());
            pd.insert(p);
        }
        public void searchAll()
        {
            List_Writeinfo(pd.selectAll());
        }
        public void searchByNum()
        {
            Console.WriteLine("제품의 번호를 입력해");
            Product p = pd.selectByNum(Int32.Parse(Console.ReadLine()));
            if (p == null)
            {
                Console.WriteLine("없다");
            }
            else
            {
                Product_Writeinfo(p);
            }
        }
        public Product searchByName()
        {
            Console.WriteLine("제품의 이름을 입력해");
            Product p = pd.selectByName(Console.ReadLine());
            if (p == null)
            {
                Console.WriteLine("없다");
            }
            else
            {
                Product_Writeinfo(p);
            }
            return p;
        }
        public void editProduct()
        {
            Product p = new Product();
            Console.WriteLine("바꿀 제품의 번호를 입력해");
            p.Num = Int32.Parse(Console.ReadLine());
            Console.WriteLine("새로운 이름을 입력해");
            p.Name = Console.ReadLine();
            Console.WriteLine("새로운 가격을 입력해");
            p.Price = Int32.Parse(Console.ReadLine());
            Console.WriteLine("새로운 수량을 입력해");
            p.Quantity = Int32.Parse(Console.ReadLine());
            pd.edit(p);
        }
        public void delProduct()
        {
            Console.WriteLine("삭제할 제품의 번호를 입력해");
            pd.del(Int32.Parse(Console.ReadLine()));
        }
        public void AranList()
        {
            pd.ArrList();
        }
        public void List_Writeinfo(List<Product> list)
        {
            foreach (Product p in list)
            {
                Console.WriteLine(p);
            }
        }

        public void Product_Writeinfo(Product p)
        {
            Console.WriteLine(p);
        }
    }
    interface CvsService
    {
        void order();
        void orderList();
        void orderDel();
    }
    class ConsolServiceConv : CvsService
    {
        private OrderDao od;
        private ProductDao pd;

        public ConsolServiceConv(OrderDao od, ProductDao pd)
        {
            this.od = od;
            this.pd = pd;
        }
        public void order()
        {
            Order or = new Order();
            List<Product> list = pd.selectAll();
            Console.WriteLine("=================상품 목록=====================");
            foreach (Product pro in list)
            {
                Console.WriteLine(pro);
            }
            Console.WriteLine("주문할 제품의 이름을 입력해");
            Product p = pd.selectByName(Console.ReadLine());
            or.Pro_num = p.Num;
            Console.WriteLine("주문할 제품의 수량을 입력해");
            int quantity = Int32.Parse(Console.ReadLine());
            or.Quantity = quantity;
            or.TotalPrice = quantity * p.Price;
            od.insert(or);
            Console.WriteLine("주문이 완료되었습니다");
        }
        public void orderList()
        {
            List<Order> list=od.selectAll();
            Console.WriteLine("====================주문 목록====================");
            foreach (Order or in list)
            {
                Console.WriteLine(or);
            }
        }
        public void orderDel()
        {
            orderList();
            Console.WriteLine("취소할 제품의 번호를 입력해");
            od.del(Int32.Parse(Console.ReadLine()));
        }
    }

    class Program
    {
        static void factory(ProductService service)
        {
            bool flag = true;
            int menu = 0;

            while (flag)
            {
                Console.WriteLine("\n1. 추가");
                Console.WriteLine("2. 전부 출력");
                Console.WriteLine("3. 넘버로 검색");
                Console.WriteLine("4. 이름으로 검색");
                Console.WriteLine("5. 수정");
                Console.WriteLine("6. 번호로 삭제");
                Console.WriteLine("7. 출고");
                Console.WriteLine("8. 번호 정렬");
                Console.WriteLine("9. 종료");
                Console.Write(">>");
                menu = Int32.Parse(Console.ReadLine());

                switch (menu)
                {
                    case 1:
                        service.addProduct();
                        break;
                    case 2:
                        service.searchAll();
                        break;
                    case 3:
                        service.searchByNum();
                        break;
                    case 4:
                        service.searchByName();
                        break;
                    case 5:
                        service.editProduct();
                        break;
                    case 6:
                        service.delProduct();
                        break;
                    case 7:
                        service.makeOrder();
                        break;
                    case 8:
                        service.AranList();
                        break;
                    case 9: flag = false;
                        break;
                    default: break;
                }
            }
        }

        static void convenience(CvsService ConService)
        {
            
            bool flag = true;
            int menu = 0;

            while (flag)
            {
                Console.WriteLine("\n1. 주문, 2.주문내역, 3.주문취소, 4.판매, 5.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1: ConService.order();
                        break;
                    case 2: ConService.orderList();
                        break;
                    case 3: ConService.orderDel();
                        break;
                    case 5:
                        flag = false;
                        break;
                    default: break;
                }

            }
        }

        static void Main(string[] args)
        {
            OrderDao od = new OracleOrderDao();
            ProductDao pd = new OracleProductDao();
            ProductService csp = new ConsolServiceProd(od,pd);
            CvsService csc = new ConsolServiceConv(od,pd);
            bool flag = true;
            int menu = 0;

            while (flag)
            {
                Console.WriteLine("1. 공장, 2.편의점, 3.종료");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1:
                        factory(csp);  //같은클래스 멤버니까 클래스이름없이 출력
                        break;
                    case 2:
                        convenience(csc);
                        break;
                    case 3:
                        flag = false;
                        break;
                }

            }
        }
    }
}

       
    


