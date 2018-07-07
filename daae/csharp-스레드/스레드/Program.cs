using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace 스레드
{
    static class Program
    {
        public static Form1 f;
        /// <summary>
        /// 해당 응용 프로그램의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            f = new Form1();
            Application.Run(f);
        }
    }
}