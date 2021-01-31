#include <opencv4/opencv2/opencv.hpp>

int main(int argc, char **argv) {

    cv::VideoCapture video_capture;
    if (!video_capture.open(0)) {
        return 0;
    }

    cv::Mat frame;
    while (true) {
        video_capture >> frame;

        imshow("Image", frame);
        const int esc_key = 27;
        if (cv::waitKey(10) == esc_key) { 
            break;
        }
    }

    cv::destroyAllWindows();
    video_capture.release();

    return 0;
}

