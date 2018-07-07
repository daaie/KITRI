using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.OleDb;

namespace 고객관리
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
    class Customer
    {
        private string id;
        private string pwd;
        private string name;
        private string email;
        
        public string Id
        {
            get 
            {
                return id;
            }
            set
            {
                id= value;
            }
        }
                public string Pwd
        {
            get 
            {
                return pwd;
            }
            set
            {
                pwd= value;
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
                name= value;
            }
        }
                public string Email
        {
            get 
            {
                return email;
            }
            set
            {
                email= value;
            }
        }
        public override string ToString() 
        {
            return "\nID : " + id + ", Pwd:" + pwd + ", Name:" + name + ", Email :" + email;
        }

    }
    interface CustomerDao
    {
        void register(Customer c);
        void edit(Customer c);
        void del(string id);
        bool match(string id,string pwd);
        void DBClose();
    }

    class OracleCustomerDao : CustomerDao
    {
        private DBConnect db; //디비 커넥트 객체
        private OleDbConnection conn;

        public OracleCustomerDao()
        {
            db = new DBConnect();
            conn = db.conn("hr", "hr", "xe");
        }
        public void register(Customer c)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("insert into customer values('{0}','{1}','{2}','{3}')", c.Id, c.Pwd,c.Name,c.Email);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 추가 가입 예외발생");
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
        public void edit(Customer c)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("update customer set name='{0}',email='{1}' where id='{2}'",c.Name,c.Email,c.Id) ;
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                int idx = cmd.ExecuteNonQuery();
                if (idx < 1)
                {
                    throw new Exception(" 수정 에러");
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
        public void del(string id)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("delete from customer where id='{0}'" , id);
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
        public bool match(string id,string pwd)
        {
            string sql;
            try
            {
                conn.Open();
                sql = string.Format("select pwd from customer where id='{0}'", id);
                OleDbCommand cmd = new OleDbCommand(sql, conn);
                OleDbDataReader read = cmd.ExecuteReader();
                while (read.Read())
                {
                    if(pwd==read.GetString(0))
                        return true;
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
            return false;
        }
        public void DBClose()
        {
            if (conn != null)
            {
                conn.Close();
              //  Console.WriteLine("\n데이터베이스연결해제\n");
            }
        }
    }
    interface Service
    {
        void register();
        void login();
        void edit();
        void del();
    }
    class ConsoleService : Service
    {
        private CustomerDao cd=null;
        private string id;

        public ConsoleService(CustomerDao cd)
        {
            this.cd=cd;
        }
        public void  register()
        {
 	        Customer c=new Customer();
            Console.WriteLine("==========회원가입==========");
            Console.Write("Id : ");
            c.Id=Console.ReadLine();
            Console.Write("Pwd : ");
            c.Pwd=Console.ReadLine();
            Console.Write("Name : ");
            c.Name=Console.ReadLine();
            Console.Write("Email : ");
            c.Email=Console.ReadLine();

            cd.register(c);
        }   
     
        public void login()
        {
            string pwd;
            bool check;
 	        Console.WriteLine("==========로그인==========");
            Console.Write("Id : ");
            id=Console.ReadLine();
            Console.Write("Pwd : ");
            pwd=Console.ReadLine();

            check=cd.match(id,pwd);
            if (check == true)
            {
                Console.WriteLine("\n로그인에 성공하였습니다");
                Console.WriteLine("{0} 님 환영합니다\n", id);
            }
            else
            {
                Console.WriteLine("\n로그인에 실패하였습니다\n");
            }
        }

        public void edit()
        {
            Customer c = new Customer();
            Console.WriteLine("==========개인정보 수정==========");
            Console.Write("Pwd : ");
            string pwd = Console.ReadLine();
            bool check = cd.match(id, pwd);
            if (check == true)
            {
                c.Id = id;
                c.Pwd = pwd;
                Console.Write("바꿀 이름 입력 : ");
                c.Name = Console.ReadLine();
                Console.Write("바꿀 이메일 입력 : ");
                c.Email = Console.ReadLine();
                cd.edit(c);
            }
        }

        public void del()
        {
            cd.del(id);
            Console.WriteLine("탈퇴가 완료되었습니다");
        }

}
class Program
    {
        static void Main(string[] args)
        {
            CustomerDao cd = new OracleCustomerDao();
            Service service = new ConsoleService(cd);
            bool flag = true;
            int menu = 0;

            while (flag)
            {
                Console.WriteLine("1. 회원가입, 2.로그인, 3.내정보수정, 4.탈퇴");
                menu = Int32.Parse(Console.ReadLine());
                switch (menu)
                {
                    case 1:
                        service.register(); 
                        break;
                    case 2:
                        service.login();
                        break;
                    case 3:
                        service.edit();
                        break;
                    case 4:
                        service.del();
                        break;
                    case 5:
                        flag = false;
                        break;
                }

            }
        }
        
    }
}
