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

2. generate "at.txt"

    First, download the file "face.rar" and decompress it. Create a new folder named "s41" in the folder "att_faces". Copy the files generated in the 1st step to this folder. Open the code "generate txt.cpp", change the path "C:\\face\\att_faces\\s" to the path of your files. Change the loop (i>=41) according to the number of your captured faces. If you have captured faces from more than one person, you can create folder "s42", "s43" and so on. 
    
    After doing these changes, run the code and you will get the file "at.txt".
    
3. train the model

    Open the code "train.cpp" and change the path "C:\\face\\att_faces\\at.txt" to the path of your "at.txt" file. 
    
    After that, run the code (a long time passed) and you will get the file "MyFacePCAModel.xml".

4. test the model

    Open the code "test.cpp" and copy the file "MyFacePCAModel.xml" to your project's path. Change the string in the "putText" function to the name of your tested person.
    
    After doing these changes, run the code and let the tested person seat in front of the camera. Adjust the position to let the face in the center of the video, then the name of the tested person will appear on the top-left of the rectangle.
    
    ![image](https://github.com/zhongzebin/face-recognition/blob/master/pictures%20for%20readme/test.png)
