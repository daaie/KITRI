using System;
using System.Collections.Generic;
using System.Text;
//멤버변수는 protected : 상속관계한테는 퍼블릭하게 안상속한애는 프라이빗하게 보이는것
namespace 피카추
{
    abstract class Character
    {
        protected int hp, exp, level;
        protected int maxhp, maxexp;
        public bool live;
        public abstract void eat();
        public abstract void play();
        public abstract void sleep();
        public abstract void exercise();
        public abstract void levelup(int extraExp);
        public abstract void dead();
        //c추상 메소드를 하나라도 가지고 있는 클래스는 추상 클래수여야함
        public Character()
        {
            level = 1;
        }
        public override string ToString()
        {
            return "\nLv = " + level + "\nhp = " + hp + " / " + maxhp + "\nexp = " + exp + " / " + maxexp;
        }

    }

    class Pikachu : Character
    {
        public Pikachu()
        {
            maxhp = 100;
            maxexp = 100;
            hp = maxhp;
            live = true;
            Console.WriteLine("***************");
            Console.WriteLine("피카츄를 잡았다");
            Console.WriteLine("***************");
        }

        public override void eat()
        {
            Console.WriteLine("피카츄 밥먹는 중...");
            if (hp < maxhp - 50)
            {
                hp += 50;
            }
            else if (hp >= maxhp - 50)
            {
                hp = maxhp;
            }

            if (exp < 10)
            {
                exp = 0;
            }

            if (exp >= 10)
            {
                exp -= 10;
            }

            Console.WriteLine("hp가 올랐다.");
            Console.WriteLine("exp가 내려갔다.");
        }
        public override void play()
        {
            Console.WriteLine("피카츄 노는 중...");
            if (exp < maxexp - 30)
            {
                exp += 30;
            }
            else if (exp >= maxexp - 30)
            {
                levelup(maxexp - exp);
            }

            if (hp < 15)
            {
                dead();
                return;
            }
            else if (hp > 15)
            {
                hp -= 15;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void sleep()
        {
            Console.WriteLine("피카츄 자는 중...");
            if (exp < maxexp - 5)
            {
                exp += 5;
            }
            else if (exp >= maxexp - 5)
            {
                levelup(maxexp - exp);
            }

            if (hp < maxhp - 3)
            {
                hp += 3;
            }
            else if (hp >= maxhp - 3)
            {
                hp = maxhp;
            }
            Console.WriteLine("exp가 조금 올랐다.");
            Console.WriteLine("hp가 조금 올랐다.");
        }
        public override void exercise()
        {
            Console.WriteLine("피카츄 운동하는 중");
            if (exp < maxexp - 50)
            {
                exp += 50;
            }
            else if (exp >= maxexp - 50)
            {
                levelup(maxexp - exp);
            }

            if (hp < 45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void levelup(int extraExp)
        {
            Console.WriteLine("***************************");
            Console.WriteLine("우와 피카츄의 레벨이 올랐다");
            Console.WriteLine("***************************");
            level++;
            maxhp = level * maxhp;
            maxexp = level * maxexp;
            exp = extraExp;
        }
        public void 전기공격() 
        {
            Console.WriteLine("백만볼트");
            if (exp < maxexp - 50)
            {
                exp += 50;
            }
            else if (exp >= maxexp - 50)
            {
                levelup(maxexp - exp);
            }

            if (hp < 45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }
        }
        public override void dead()
        {
            Console.WriteLine("\n으앙 피카츄가 죽었다ㅠㅠ\n");
            hp = 0;
            exp = 0;
            live = false;
        }
    }
    class Squirtle : Character
    {
        public Squirtle()
        {
            maxhp = 200;
            maxexp = 100;
            hp = maxhp;
            live = true;
            Console.WriteLine("***************");
            Console.WriteLine("꼬부기를 잡았다");
            Console.WriteLine("***************");
        }

        public override void eat()
        {
            Console.WriteLine("꼬부기 밥먹는 중...");
            if (hp < maxhp - 30)
            {
                hp += 30;
            }
            else if (hp >= maxhp - 30)
            {
                hp = maxhp;
            }

            if (exp < 10)
            {
                exp = 0;
            }

            if (exp >= 10)
            {
                exp -= 10;
            }

            Console.WriteLine("hp가 올랐다.");
            Console.WriteLine("exp가 내려갔다.");
        }
        public override void play()
        {
            Console.WriteLine("꼬부기 노는 중...");
            if (exp < maxexp - 30)
            {
                exp += 30;
            }
            else if (exp >= maxexp - 30)
            {
                levelup(maxexp - exp);
            }

            if (hp < 15)
            {
                dead();
                return;
            }
            else if (hp > 15)
            {
                hp -= 15;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void sleep()
        {
            Console.WriteLine("꼬부기 자는 중...");
            if (exp < maxexp - 5)
            {
                exp += 5;
            }
            else if (exp >= maxexp - 5)
            {
                levelup(maxexp - exp);
            }

            if (hp < maxhp - 3)
            {
                hp += 3;
            }
            else if (hp >= maxhp - 3)
            {
                hp = maxhp;
            }
            Console.WriteLine("exp가 조금 올랐다.");
            Console.WriteLine("hp가 조금 올랐다.");
        }
        public override void exercise()
        {
            Console.WriteLine("꼬부기 운동하는 중");
            if (exp < maxexp - 50)
            {
                exp += 50;
            }
            else if (exp >= maxexp - 50)
            {
                levelup(maxexp - exp);
            }

            if (hp < 45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void levelup(int extraExp)
        {
            Console.WriteLine("***************************");
            Console.WriteLine("우와 꼬부기의 레벨이 올랐다");
            Console.WriteLine("***************************");
            level++;
            maxhp = level * maxhp;
            maxexp = level * maxexp;
            exp = extraExp;
        }
        public void 물대포()
        {
            Console.WriteLine("물대포");
            if (exp < maxexp - 50)
            {
                exp += 50;
            }
            else if (exp >= maxexp - 50)
            {
                levelup(maxexp - exp);
            }

            if (hp < 45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }
        }
        public override void dead()
        {
            Console.WriteLine("\n으앙 꼬부기가 죽었다ㅠㅠ\n");
            hp = 0;
            exp = 0;
            live = false;
        }
    }
    class Bulbasaur : Character
    {
        public Bulbasaur()
        {
            maxhp = 50;
            maxexp = 100;
            hp = maxhp;
            live = true;
            Console.WriteLine("***************");
            Console.WriteLine("이상해씨를 잡았다");
            Console.WriteLine("***************");
        }

        public override void eat()
        {
            Console.WriteLine("이상해씨 밥먹는 중...");
            if (hp < maxhp - 50)
            {
                hp += 50;
            }
            else if (hp >= maxhp - 50)
            {
                hp = maxhp;
            }

            if (exp < 10)
            {
                exp = 0;
            }

            if (exp >= 10)
            {
                exp -= 10;
            }

            Console.WriteLine("hp가 올랐다.");
            Console.WriteLine("exp가 내려갔다.");
        }
        public override void play()
        {
            Console.WriteLine("이상해씨 노는 중...");
            if (exp < maxexp - 80)
            {
                exp += 80;
            }
            else if (exp >= maxexp - 80)
            {
                levelup(maxexp - exp);
            }

            if (hp <= 25)
            {
                dead();
                return;
            }
            else if (hp > 25)
            {
                hp -= 25;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void sleep()
        {
            Console.WriteLine("이상해씨 자는 중...");
            if (exp < maxexp - 5)
            {
                exp += 5;
            }
            else if (exp >= maxexp - 5)
            {
                levelup(maxexp - exp);
            }

            if (hp < maxhp - 3)
            {
                hp += 3;
            }
            else if (hp >= maxhp - 3)
            {
                hp = maxhp;
            }
            Console.WriteLine("exp가 조금 올랐다.");
            Console.WriteLine("hp가 조금 올랐다.");
        }
        public override void exercise()
        {
            Console.WriteLine("이상해씨 운동하는 중");
            if (exp < maxexp - 90)
            {
                exp += 90;
            }
            else if (exp >= maxexp - 90)
            {
                levelup(maxexp - exp);
            }

            if (hp <=
                45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }

            Console.WriteLine("exp가 올랐다.");
            Console.WriteLine("hp가 내려갔다.");
        }
        public override void levelup(int extraExp)
        {
            Console.WriteLine("***************************");
            Console.WriteLine("우와 이상해씨의 레벨이 올랐다");
            Console.WriteLine("***************************");
            level++;
            maxhp = level * maxhp;
            maxexp = level * maxexp;
            exp = extraExp;
        }
        public void 넝쿨채찍()
        {
            Console.WriteLine("넝쿨채찍");
            if (exp < maxexp - 50)
            {
                exp += 50;
            }
            else if (exp >= maxexp - 50)
            {
                levelup(maxexp - exp);
            }

            if (hp < 45)
            {
                dead();
                return;
            }
            else if (hp > 45)
            {
                hp -= 45;
            }
        }
        public override void dead()
        {
            Console.WriteLine("\n으앙 이상해씨가 죽었다ㅠㅠ\n");

            hp = 0;
            exp = 0;
            live = false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int menu;
            bool flag;
            bool flag2 = true;
            Character c = null;
            while (flag2)
            {
                flag = true;
                Console.WriteLine("\n===========새 게임=============\n");
                Console.WriteLine("캐릭터를 골라주세요");
                Console.WriteLine("1.피카츄 2.꼬부기 3.이상해씨 4.종료");
                try
                {
                    menu = Int32.Parse(Console.ReadLine());
                }
                catch (Exception ex)
                {
                    menu = 0;
                }

                switch (menu)
                {
                    case 1: c = new Pikachu();
                        break;
                    case 2: c = new Squirtle();
                        break;
                    case 3: c = new Bulbasaur();
                        break;
                    case 4: return;
                        break;
                    default: break;
                }

                while (flag)
                {
                    Console.WriteLine("\n무엇을 할까요?");
                    Console.WriteLine("1.밥먹기 2.놀기 3.자기 4.운동하기 5.특수공격 6.종료\n");
                    try
                    {
                    menu = Int32.Parse(Console.ReadLine());
                    }
                    catch (Exception ex)
                    {
                        menu = 0;
                    }
                    switch (menu)
                    {
                        case 1: c.eat();
                            break;
                        case 2: c.play();
                            break;
                        case 3: c.sleep();
                            break;
                        case 4: c.exercise();
                            break;
                        case 5:
                            if (c is Pikachu)
                            {
                                ((Pikachu)c).전기공격();
                            }
                            else if (c is Squirtle)
                            {
                                ((Squirtle)c).물대포();
                            }
                            else if (c is Bulbasaur)
                            {
                                ((Bulbasaur)c).넝쿨채찍();
                            }
                            break;
                        case 6: flag = false;
                            break;
                        default: break;
                    }

                    if (!c.live)
                    {
                        flag = false;
                    }
                    else
                    {
                        Console.WriteLine(c);
                    }
                }
            }
        }
    }
}
