using System;
using System.Collections.Generic;
using System.Text;

namespace db인터페이스
{
    class Point
    {
        public int x;
        public int y;

    }
    interface Dao
    {
        void insert(Point p);
        void selectAll();
        void edit(Point p);
        void delete(int x);
    }

    class OracleDao : Dao
    {
        #region Dao 멤버

        public void insert(Point p)
        {
            Console.WriteLine("Oracle insert");
        }

        public void selectAll()
        {
            Console.WriteLine("Oracle selectAll");
        }

        public void edit(Point p)
        {
            Console.WriteLine("Oracle edit");
        }
             
        public void delete(int x)
        {
            Console.WriteLine("Oracle delete");
        }

        #endregion
    }
    class MsDao : Dao
    {
        #region Dao 멤버

        public void insert(Point p)
        {
            Console.WriteLine("MsDao insert");
        }

        public void selectAll()
        {
            Console.WriteLine("MsDao selectAll");
        }

        public void edit(Point p)
        {
            Console.WriteLine("MsDao edit");
        }

        public void delete(int x)
        {
            Console.WriteLine("MsDao delete");
        }

        #endregion
    }
    interface Service
    {
        void addPoint();
        void getPoints();
        void editPoint();
        void delPoint();
    }
    class School1Service : Service
    {
        //수정이 용이하기 위해 인터페이스 데이터 타입을 형식으로 선언해줌 
        Dao dao;
        public School1Service(Dao dao)
        {
            this.dao = dao; //dao를 파라메터로 받아오므로 의존성을 떼줌  
        }
        #region Service 멤버

        public void addPoint()
        {
            Console.WriteLine("SEsevice addPoint");
            dao.insert(new Point());
        }

        public void getPoints()
        {
            Console.WriteLine("SEsevice  getPoints");
            dao.selectAll();
        }

        public void editPoint()
        {
            Console.WriteLine("SEsevice editPoint");
            dao.edit(new Point());
        }

        public void delPoint()
        {
            Console.WriteLine("SEsevice delPoint");
            dao.delete(3);
        }

        #endregion
    }
class Program
    {
        static void Main(string[] args)
        {
            Service service = new School1Service(new OracleDao());
            service.addPoint();
            service.getPoints();
            service.editPoint();
            service.delPoint();
        }
    }
}
