#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace  std;

int main(int argc,char **argv){
    try {
        if(argc!=4)throw  std::runtime_error("Usage file w h");
        string filep=argv[1];
        int width=stoi(argv[2]);
        int height=stoi(argv[3]);
        ifstream file(filep);
        if(!file) throw  std::runtime_error("Could not open file");
        int sizebytes=width*height*1.5;
        cv::Mat image(height,width,CV_8UC1);
        file.read(image.ptr<char>(0),width*height);
        cv::imwrite("out.jpg",image);

    } catch (const std::exception &ex) {

        cerr<<ex.what()<<endl;
    }
}
