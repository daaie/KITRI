using System;
using System.Collections.Generic;
using System.Text;

namespace _.링크드리스트
{
    class Member
    {
        private string name;
        private string tel;
        private string address;

        public Member() { }
        public Member(string n, string t, string a)
        {
            name = n;
            tel = t;
            address = a;
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
        public string Tel
        {
            get
            {
                return tel;
            }
            set
            {
                tel = value;
            }
        }
        public string Address
        {
            get
            {
                return address;
            }
            set
            {
                address = value;
            }
        }
        public void print(int a)
        {
            Console.WriteLine("========={0}번째 사람============",a+1);
            Console.WriteLine("이름 : {0}", Name);
            Console.WriteLine("전화번호 : {0}",Tel);
            Console.WriteLine("주소 : {0}", Address);
        }
    }

    class AddressList
    {
        private Member[] data;
        private int cnt;

        public AddressList()
        {
            data = new Member[30];
            cnt = 0;
        }
        public void insert(Member m)
        {
            if (cnt > 29)
            {
                Console.WriteLine("가득찼다..");
                return;
            }
            data[cnt++] = m;

        }
        public void printAll()
        {
            for(int i=0;i<cnt;i++)
            {
                data[i].print(i);
            }
        }
        public int search(string name)
        {
            for (int i = 0; i < cnt; i++)
            {
                //if (!((String.Compare(data[i].Name,name))!=0))
                if(name==data[i].Name)
                {
                    data[i].print(i);
                    return i;
                }
            }
            Console.WriteLine("\n못찾았당..ㅜㅜ\n");
            return -1;
        }
        public void edit(string name)
        {
            int order;
            order=search(name);
            if (order == -1) return;
            Console.WriteLine("바꿀 전화번호 ? = ");
            data[order].Tel = Console.ReadLine();
            Console.WriteLine("바꿀 주소 ? = ");
            data[order].Address = Console.ReadLine();
        }
        public void del(string name)
        {
            int order;
            order = search(name);
            if (order == -1) return;
            for (int i = order; i < cnt-1; i++)
            {
                data[i] = data[i + 1];
            }
            data[cnt] = null;
            cnt--;
        }
   
    }
    class Program
    {
        static void Main(string[] args)
        {
            int menu;
            bool flag=true;
            string name,tel,add;
            AddressList al = new AddressList();

            while (flag)
            {
                Console.WriteLine("=========메뉴============");
                Console.WriteLine("1.추가");
                Console.WriteLine("2.전부출력");
                Console.WriteLine("3.검색");
                Console.WriteLine("4.수정");
                Console.WriteLine("5.삭제");
                Console.WriteLine("6.종료");
                Console.Write(">>  ");
                menu = Int32.Parse(Console.ReadLine());

                switch (menu)
                {
                    case 1 :
                        Console.WriteLine("추가할 이름?");
                        name = Console.ReadLine();
                        Console.WriteLine("추가할 전화?");
                        tel = Console.ReadLine();
                        Console.WriteLine("추가할 주소?");
                        add = Console.ReadLine();
                        al.insert(new Member(name,tel,add));
                        break;
                    case 2:
                        al.printAll();
                        break;
                    case 3:
                        Console.Write("찾을 이름?");
                        al.search(Console.ReadLine());
                        break;
                    case 4:
                        Console.Write("수정할 이름?");
                        al.edit(Console.ReadLine());
                        break;
                    case 5:
                        Console.Write("삭제할 이름?");
                        al.del(Console.ReadLine());
                        break;
                    case 6:
                        flag = false;
                        break;
                    default: break;
                }


            }
        }
    }
}
