#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;

string pixelToString(int pixelIntensity) {
    const string ASCII_CHARS = "#@%&?+:,.  ";
    return string(1, ASCII_CHARS[pixelIntensity * ASCII_CHARS.length() / 256]);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <video_absolute_path> [ascii_width]" << endl;
        return 1;
    }

    string videoPath = argv[1];
    int resizedWidth = (argc > 2) ? stoi(argv[2]) : 130;

    VideoCapture cap(videoPath);
    if (!cap.isOpened()) {
        cerr << "Error: Could not open video file." << endl;
        return 1;
    }

    double fps = cap.get(CAP_PROP_FPS);
    int delay = 1000 / fps;

    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);
    int resizedHeight = resizedWidth * height / width;

    Mat frame, grayFrame, resizedFrame;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
        resize(grayFrame, resizedFrame, Size(resizedWidth, resizedHeight));

        for (int i = 0; i < resizedHeight; i++) {
            for (int j = 0; j < resizedWidth; j++) {
                cout << pixelToString(resizedFrame.at<uchar>(i, j));
            }
            cout << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    return 0;
}