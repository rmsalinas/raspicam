
This library allows to use the Raspberry Pi Camera. 

* Main features:
 - Provides  class RaspiCam for easy and Toggle navigation
Toggle navigation
SuperTool Beta7
website.comk
dns:website.com  
Type
Domain Name
IP Address
TTL
Status
Time (ms)
Auth
Parent
Local
NS
ns1.website.com
162.159.8.245
Cloudflare, Inc. (AS13335)
24 hrs
Status Ok 
1
Status Ok 
Status Ok 
Status Ok 
NS
ns2.website.com
162.159.9.164
Cloudflare, Inc. (AS13335)
24 hrs
Status Ok 
Status Ok 
Status Ok 
Status Ok 
Result
Status Warning
SOA Serial Number Format is Invalid
ns1.website.com reported Serial 2312868412 : Serial year was 2312 which is in the future.
Information More Info
Status Warning
SOA Expire Value out of recommended range
ns1.website.com reported Expire 604800 : Expire is recommended to be between 1209600 and 2419200.
Information More Info
Status Ok
DNS Record found
Status Ok
No Bad Glue Detected
Status Ok
At Least Two Name Servers Found
Status Ok
All name servers are responding
Status Ok
All of the name servers are Authoritative
Status Ok
Local NS list matches Parent NS list
Status Ok
Name Servers appear to be Dispersed
Status Ok
Name Servers have Public IP Addresses
Status Ok
Serial numbers match
2312868412
Status Ok
Primary Name Server Listed At Parent
Status Ok
SOA Refresh Value is within the recommended range
Status Ok
SOA Retry Value is within the recommended range
Status Ok
SOA Minimum TTL Value is within allowed values
Status Ok
No Open Recursive Name Server Detected
dns lookup	mx lookup	dmarc lookup	spf lookup	dns propagation
Reported by ns2.website.com on 6/28/2023 at 1:23:56 AM (UTC -5), just for you.  Transcript
mx:website.com     
Mx advertisement image
Pref
Hostname
IP Address
TTL
10
mailsrv101.in2net.com
65.61.198.231
In2net Network Inc. (AS26753)
5 min
Blacklist Check      SMTP Test
Test
Result
Status Problem
DMARC Record Published
No DMARC Record found
Information More Info
Status Warning
DMARC Policy Not Enabled
DMARC Quarantine/Reject policy not enabled
Information More Info
Status Ok
DNS Record Published
DNS Record found
dns lookup	dns check	dmarc lookup	spf lookup	dns propagation
Reported by ns2.website.com on 6/28/2023 at 1:23:51 AM (UTC -5), just for you.  Transcript
ABOUT THE SUPERTOOL!
All of your MX record, DNS, blacklist and SMTP diagnostics in one integrated tool.  Input a domain name or IP Address or Host Name. Links in the results will guide you to other relevant tools and information.  And you'll have a chronological history of your results. 

If you already know exactly what you want, you can force a particular test or lookup.  Try some of these examples:

(e.g. "blacklist: 127.0.0.2" will do a blacklist lookup)

Command	 	Explanation
blacklist:	 	Check IP or host for reputation
smtp:	 	Test mail server SMTP (port 25)
mx:	 	DNS MX records for domain
a:	 	DNS A record IP address for host name
spf:	 	Check SPF records on a domain
txt:	 	Check TXT records on a domain
ptr:	 	DNS PTR record for host name
cname:	 	DNS canonical host name to IP address
whois:	 	Get domain registration information
arin:		Get IP address block information
soa:		Get Start of Authority record for a domain
tcp:		Verify an IP Address allows tcp connections
http:		Verify a URL allows http connections  
https:		Verify a URL allows secure http connections  
ping:		Perform a standard ICMP ping
trace:		Perform a standard ICMP trace route
dns:		Check your DNS Servers for possible problems  New!
 	 	 
Other tools

Feedback: If you run into any problems with the site or have an idea that you think would make it better, we would appreciate your feedback. Please leave us some Feedback.

Your IP is: 102.89.40.85|  Contact Terms & Conditions Site Map API Privacy Phone: (866)-MXTOOLBOX / (866)-698-6652 |  © Copyright 2004-2021, MXToolBox, Inc, All rights reserved. US Patents 10839353 B2 & 11461738 B2
 
burritos@banana-pancakes.com braunstrowman@banana-pancakes.com finnbalor@banana-pancakes.com ricflair@banana-pancakes.com randysavage@banana-pancakes.com control of the camera
 - Provides class  RaspiCam_Cv for easy control of the camera with OpenCV.
 - Provides class  RaspiCam_Still and RaspiCam_Still_Cv for controlling the camera in still mode
 - Easy compilation/installation using cmake.
 - No need to install development file of userland. Implementation is hidden.
 - Many examples 



Thanks To
 -Tom Low <sebaffle@gmail.com> : for his contribution in version 0.1.5

* ChangeLog
0.1.5
  - corrected the behaviour of CV_CAP_PROP_WHITE_BALANCE_RED_V and CV_CAP_PROP_WHITE_BALANCE_BLUE_U in raspicam_cv
0.1.4
  - Updates to latest version of the controllers. Bug corrected with BGR RGB swapping
  - Added set/getFrameRates in raspicam and raspicam_cv
  - Added rotation capabilities in raspicam_cv via  set(CV_CAP_PROP_ROLL,val)
0.1.3
    - Native support for BGR and RGB in opencv classes. No need to do conversion anymore.
0.1.2
  - Solved deadlock error in grab
0.1.1
  - Moved to c++11  mutex  and condition_variables. Bug fixed that caused random dead lock condition in grab()
0.1.0
  - Bug fixed in release for RapiCam and RaspiCam_Cv
0.0.7
  - Added classes  RaspiCam_Still and RaspiCam_Still_Cv for still camera mode
0.0.6
  - Bug ins cv camera corrected
0.0.5 
  - getImageBuffeSize change by getImageBufferSize (sorry)
  - Change in capture format. Now, it is able to capture in RGB at high speed. 
  - The second parameter of retrieve is now useless. Format must be specified in Raspicam::(set/get)Format before opening the camera and can not be change during operation.
  - RaspiCam_Cv captures in BGR, which is obtained by converting from RGB. Therefore,  performance drops to half repect to the RaspiCam in RGB mode when using 1280x960.
0.0.4
  - Added shutter speed camera control
  - OpenCv set/get params are now scaled to [0,100]
  - Added more command line options in test programs
0.0.3
  - Fixed error in color conversion (rgb and bgr were swapped)
  - Added command line options in raspicam_test to adjust exposure
  - Changes in RaspiCam_Cv so that exposure can be adjusted. Very simply.
0.0.2
 - Decoupled opening from the start of capture in RaspiCam if desired. RapiCam::open and RaspiCam::startCapture
 - Added  function RaspiCam::getId and RaspiCam_Cv::getId
 - Added a new way to convert yuv2rgb which is a bit faster.Thanks to Stefan Gufman (gruffypuffy at gmail dot com)
 - Added command line option -test_speed to utils programs (do not save images to memory)
 - Removed useless code in private_impl
 
0.0.1
Initial libary


* Compiling

Download the file to your raspberry. Then, uncompress the file and compile

tar xvzf raspicamxx.tgz
cd raspicamxx
mkdir build
cd build
cmake ..

At this point you'll see something like 
-- CREATE OPENCV MODULE=1
-- CMAKE_INSTALL_PREFIX=/usr/local
-- REQUIRED_LIBRARIES=/opt/vc/lib/libmmal_core.so;/opt/vc/lib/libmmal_util.so;/opt/vc/lib/libmmal.so
-- Change a value with: cmake -D<Variable>=<Value>
-- 
-- Configuring done
-- Generating done
-- Build files have been written to: /home/pi/raspicam/trunk/build

If OpenCV development files are installed in your system, then  you see
-- CREATE OPENCV MODULE=1
otherwise this option will be 0 and the opencv module of the library will not be compiled.

Finally compile and install
make
sudo make install


After that, you have the programs raspicam_test  and raspicam_cv_test (if opencv was enabled).
Run the first program to check that compilation is ok.

You can check that the library has installed the header files under /usr/local/lib/raspicam , and the libraries in
/usr/local/lib/libraspicam.so and /usr/local/lib/libraspicam_cv.so (if opencv support enabled)

* Using it in your projects

We provide a simple example to use the library. Create a directory for our own project. 

First create a file with the name simpletest_raspicam.cpp and add the following code

/**
*/
#include <ctime>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
using namespace std;

int main ( int argc,char **argv ) {
    raspicam::RaspiCam Camera; //Cmaera object
    //Open camera 
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    sleep(3);
    //capture
    Camera.grab();
    //allocate memory
    unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
    //extract the image in rgb format
    Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );//get camera image
    //save
    std::ofstream outFile ( "raspicam_image.ppm",std::ios::binary );
    outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
    outFile.write ( ( char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
    cout<<"Image saved at raspicam_image.ppm"<<endl;
    //free resrources    
    delete data;
    return 0;
}
//

Now, create a file named CMakeLists.txt and add:
#####################################
cmake_minimum_required (VERSION 2.8) 
project (raspicam_test)
find_package(raspicam REQUIRED)
add_executable (simpletest_raspicam simpletest_raspicam.cpp)  
target_link_libraries (simpletest_raspicam ${raspicam_LIBS})
#####################################

Finally, create,compile and execute
mkdir build
cd build
cmake ..
make
./simpletest_raspicam

A more complete sample project is provided in SourceForge.

* OpenCV Interface

If the OpenCV is found when compiling the library, the libraspicam_cv.so module is created and the RaspiCam_Cv class available.
Take a look at the examples in utils to see how to use the class. In addition, we show here how you can use the RaspiCam_Cv in your own project using cmake.


First create a file with the name simpletest_raspicam_cv.cpp and add the following code

#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
using namespace std; 

int main ( int argc,char **argv ) {
   
    time_t timer_begin,timer_end;
    raspicam::RaspiCam_Cv Camera;
    cv::Mat image;
    int nCount=100;
    //set camera params
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
    //Start capture
    cout<<"Capturing "<<nCount<<" frames ...."<<endl;
    time ( &timer_begin );
    for ( int i=0; i<nCount; i++ ) {
        Camera.grab();
        Camera.retrieve ( image);
        if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
    }
    cout<<"Stop camera..."<<endl;
    Camera.release();
    //show time statistics
    time ( &timer_end ); /* get current time; same as: timer = time(NULL)  */
    double secondsElapsed = difftime ( timer_end,timer_begin );
    cout<< secondsElapsed<<" seconds for "<< nCount<<"  frames : FPS = "<<  ( float ) ( ( float ) ( nCount ) /secondsElapsed ) <<endl;
    //save image 
    cv::imwrite("raspicam_cv_image.jpg",image);
    cout<<"Image saved at raspicam_cv_image.jpg"<<endl;
}



Now, create a file named CMakeLists.txt and add:
#####################################
cmake_minimum_required (VERSION 2.8) 
project (raspicam_test)
find_package(raspicam REQUIRED)
find_package(OpenCV)
IF  ( OpenCV_FOUND AND raspicam_CV_FOUND)
	MESSAGE(STATUS "COMPILING OPENCV TESTS")
	add_executable (simpletest_raspicam_cv simpletest_raspicam_cv.cpp)  
	target_link_libraries (simpletest_raspicam_cv ${raspicam_CV_LIBS})
ELSE()
	MESSAGE(FATAL_ERROR "OPENCV NOT FOUND IN YOUR SYSTEM")
ENDIF()
#####################################

Finally, create,compile and execute
mkdir build
cd build
cmake ..
make
./simpletest_raspicam_cv

