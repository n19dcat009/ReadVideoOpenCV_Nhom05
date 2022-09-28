//Code demo Group 05

//Bao g?m th? vi?n
#include<opencv2/opencv.hpp>
#include<iostream>
//Namespace vô hi?u hóa vi?c s? d?ng cv::function();
using namespace std;
using namespace cv;
int main() {
    VideoCapture vid_capture("C:\\Users\\84395\\Music\\MEmu Music\\ReadVideoOpenCV\\bandicam 2022-09-29 00-26-48-172.mp4");
    // In thong bao loi neu luong khong hop le
    if (!vid_capture.isOpened())
    {
        cout << "Error opening video stream or file" << endl;
    }
    else
    {

        // Nh?n fps và s? khung hình b?ng ph??ng th?c get () và in

        // B?n c?ng có th? thay th? 5 b?ng CAP_PROP_FPS, chúng là ki?u li?t kê              
        int fps = vid_capture.get(5);

        cout << "Frames per second :" << fps;

        int frame_count = vid_capture.get(7);

        cout << "  Frame count :" << frame_count;

    }





    // ??c các khung ??n khung cu?i cùng

    while (vid_capture.isOpened())

    {

        // Kh?i t?o ma tr?n khung

        Mat frame;



        // Kh?i t?o boolean ?? ki?m tra xem khung có ? ?ó hay không

        bool isSuccess = vid_capture.read(frame);



        // N?u có khung, hãy hi?n th? nó

        if (isSuccess == true)

        {

            //khung hi?n th?

            imshow("Frame", frame);

        }



        // N?u không có khung ? ?ó, hãy ?óng nó l?i

        if (isSuccess == false)

        {

            cout << "Video camera is disconnected" << endl;

            break;

        }



        //wait 20 ms between successive frames and break the loop if key q is pressed

        int key = waitKey(20);

        if (key == 'q')

        {

            cout << "q key is pressed by the user. Stopping the video" << endl;

            break;

        }





    }

    // Release the video capture object

    vid_capture.release();

    destroyAllWindows();

    return 0;

}


