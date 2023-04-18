using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinSizeSav
{
    public partial class Form1 : Form
    {
        Size bounds;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            
            if (this.WindowState == FormWindowState.Minimized)
            {
                bounds = this.Size;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show(bounds.Width.ToString()+":"+bounds.Height.ToString());
        }

        private void Form1_ResizeBegin(object sender, EventArgs e)
        {
            bounds = this.Size;
        }
    }
}
