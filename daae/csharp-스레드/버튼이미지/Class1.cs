using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;



namespace 버튼이미지
{
    class MyButton : System.Windows.Forms.Control
    {
        private Image image;
        public Image BackImage
        {
            get
            {
                return this.image;
            }
            set
            {
                this.image = value;
            }

        }

        protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
        {
            if (image != null)
            {
                e.Graphics.DrawImage(image, 0, 0);

            }
            base.OnPaint(e);
        }

    }
}
