# face-recognition
Abstract: using OpenCV to recognize human faces

Environment: OpenCV3.4.1, Windows 10, Visual Studio 2017

How to configure the environment?

1. install and configure OpenCV

    https://blog.csdn.net/weixin_42731241/article/details/81626700

Special Notice: Besides configuring OpenCV, you should also add opencv_face341d.lib to the linker of your project.
    
How to run this project?

1. run "capture faces.cpp" to capture the tested person's face 

    The number of faces being captured is displayed on the top-left point of the rectangle. During the capturing process, the person being tested should move his or her face to different angles and walk to different places. I strongly stuggest the number of captured faces should be no less than 100. When you think the number of pictures is enough, press esc and the programm will quit.
    
    After running this programm, you will get a series faces of the tested person. The name of these files are: "1.jpg", "2.jpg" … "100.jpg" …
    
    ![image](https://github.com/zhongzebin/face-recognition/blob/master/pictures%20for%20readme/faces.png)
