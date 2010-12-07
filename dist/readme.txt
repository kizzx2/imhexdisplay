imhexdisplay (c) 2010 Chris Yuen <chris@kizzx2.com>

This is a simple program to allow you to view raw pixels from hex values. Very useful when you want to visualize how a pixmap looks like from your debugger.

Just drop imdebug binaries from http://www.billbaxter.com/projects/imdebug/ into the same directory and you're good to go!

Short tutorial
--------------

From your debugger, copy and paste hex values from the memory window. It should look like this:

00 ff 00 00 ff 00 01 fe 00 02 fd 00 03 fc 00 04 fb 00 05 fa 00
05 fa 00 06 f9 00 07 f8 00 08 f7 00 09 f6 00 0a f5 00 0b f4 00
0b f4 00 0c f3 00 0d f2 ...

Newlines and whitespaces are ignored.

Now start the program and put in the first line:

    rgb 300

This means the pixels are RGB values and the pixmap is 300 pixels wide. Some other valid examples are

    bgr 100
    argb 100
    rgba 100

Enjoy
