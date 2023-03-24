using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TimerStudy
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
            // 싱글쓰레드 Timer 클래스 
            System.Windows.Forms.Timer t = new System.Windows.Forms.Timer();
            
            // 멀티쓰레드 timer 클래스 
            // System.Timers.Timer t = new System.Timers.Timer();
            
            // t.Elapsed += new System.Timers.ElapsedEventHandler(test);

            t.Tick += new EventHandler(test);
            t.Interval = 1000;
            t.Start();
        }
        public void test(Object myObject,EventArgs myEventArgs)
        {
            Thread.Sleep(100000);
        }
    }
}
