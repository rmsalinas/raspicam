/**********************************************************
 Software developed by AVA ( Ava Group of the University of Cordoba, ava  at uco dot es)
 Main author Rafael Munoz Salinas (rmsalinas at uco dot es)
 This software is released under BSD license as expressed below
-------------------------------------------------------------------
Copyright (c) 2013, AVA ( Ava Group University of Cordoba, ava  at uco dot es)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:

   This product includes software developed by the Ava group of the University of Cordoba.

4. Neither the name of the University nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY AVA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AVA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
****************************************************************/

#include "raspicam_cv.h"
#include "private/private_impl.h"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include "cvversioning.h"
#include "scaler.h"
namespace raspicam {
    RaspiCam_Cv::RaspiCam_Cv() {

        set(CV_CAP_PROP_FORMAT,CV_8UC3);

    }
    RaspiCam_Cv::~RaspiCam_Cv() {
    }



    /**
    *Decodes and returns the grabbed video frame.
     */
    void RaspiCam_Cv::retrieve ( cv::Mat& image ) {
        //here we go!
        image.create ( RaspiCam::getHeight(),RaspiCam::getWidth(),imgFormat );
        RaspiCam:: retrieve ( image.ptr<uchar> ( 0 ));
//        if(imgFormat==CV_8UC1)
//            RaspiCam::retrieve ( image.ptr<uchar> ( 0 ));
//        else{
//            _image.create(RaspiCam::getHeight()+RaspiCam::getHeight()/2,RaspiCam::getWidth(),CV_8UC1);
//            RaspiCam::retrieve ( _image.ptr<uchar> ( 0 ));
//            cv::cvtColor(_image,image,CV_YUV2BGR_I420);
//        }
    }

    /**Returns the specified VideoCapture property
     */

    double RaspiCam_Cv::get ( int propId ) {

        switch ( propId ) {

        case CV_CAP_PROP_FRAME_WIDTH :
            return RaspiCam::getWidth();
        case CV_CAP_PROP_FRAME_HEIGHT :
            return RaspiCam::getHeight();
        case CV_CAP_PROP_FPS:
            return 30;
        case CV_CAP_PROP_FORMAT :
            return imgFormat;
        case CV_CAP_PROP_MODE :
            return 0;
        case CV_CAP_PROP_BRIGHTNESS :
            return RaspiCam::getBrightness();
        case CV_CAP_PROP_CONTRAST :
            return Scaler::scale ( -100,100,0,100,  RaspiCam::getContrast() );
        case CV_CAP_PROP_SATURATION :
            return  Scaler::scale ( -100,100,0,100, RaspiCam::getSaturation() );;
//     case CV_CAP_PROP_HUE : return _camRaspiCam::getSharpness();
        case CV_CAP_PROP_GAIN :
            return  Scaler::scale ( 0,800,0,100, RaspiCam::getISO() );
        case CV_CAP_PROP_EXPOSURE :
            if ( RaspiCam::getShutterSpeed() ==0 )
                return -1;//auto
            else return Scaler::scale (0,330000, 0,100, RaspiCam::getShutterSpeed() )  ;
       break;
        case CV_CAP_PROP_CONVERT_RGB :
            return ( imgFormat==CV_8UC3 );
        case CV_CAP_PROP_WHITE_BALANCE_RED_V:
            if( RaspiCam::getAWB()== raspicam::RASPICAM_AWB_AUTO)
                return -1;//auto
            else
                return RaspiCam::getAWBG_red() / 100.0f;
        break;

        case CV_CAP_PROP_WHITE_BALANCE_BLUE_U:
            if( RaspiCam::getAWB()== raspicam::RASPICAM_AWB_AUTO)
                return -1;//auto
            else
                return RaspiCam::getAWBG_blue() / 100.0f;
        break;
        default :
            return -1;
        };
    }

    /**Sets a property in the VideoCapture.
     */

    bool RaspiCam_Cv::set ( int propId, double value ) {

        switch ( propId ) {
        case CV_CAP_PROP_FPS :
            RaspiCam::setFrameRate( value );
            break;

        case CV_CAP_PROP_FRAME_WIDTH :
            RaspiCam::setWidth ( value );
            break;
        case CV_CAP_PROP_FRAME_HEIGHT :
            RaspiCam::setHeight ( value );
            break;
        case CV_CAP_PROP_FORMAT :{
            bool res=true;
            if ( value==CV_8UC1  ){
                RaspiCam::setFormat(RASPICAM_FORMAT_GRAY);
                imgFormat=value;
            }
            else if (value==CV_8UC3){
                RaspiCam::setFormat(RASPICAM_FORMAT_BGR);
                imgFormat=value;
            }
            else res=false;//error int format
            return res;
        }break;
        case CV_CAP_PROP_MODE ://nothing to  do yet
            return false;
            break;
        case CV_CAP_PROP_BRIGHTNESS :
            RaspiCam::setBrightness ( value );
            break;
        case CV_CAP_PROP_CONTRAST :
            RaspiCam::setContrast ( Scaler::scale ( 0,100,-100,100, value ) );
            break;
        case CV_CAP_PROP_SATURATION :
            RaspiCam::setSaturation ( Scaler::scale ( 0,100,-100,100, value ) );
            break;
//     case CV_CAP_PROP_HUE : return _camRaspiCam::getSharpness();
        case CV_CAP_PROP_GAIN :
            RaspiCam::setISO ( Scaler::scale ( 0,100,0,800, value ) );
            break;
        case CV_CAP_PROP_EXPOSURE :
            if ( value>0 && value<=100 ) {
                RaspiCam::setShutterSpeed ( Scaler::scale ( 0,100,0,330000, value ) );
            } else {
                RaspiCam::setExposure ( RASPICAM_EXPOSURE_AUTO );
                RaspiCam::setShutterSpeed ( 0 );
            }
            break;
        case CV_CAP_PROP_CONVERT_RGB :
            imgFormat=CV_8UC3;
            break;
        case CV_CAP_PROP_WHITE_BALANCE_RED_V:
            if ( value>0 && value<=100 ) {
                float valblue=RaspiCam::getAWBG_blue();
                RaspiCam::setAWB(raspicam::RASPICAM_AWB_OFF);
                RaspiCam::setAWB_RB(value*100, valblue );
            }
            else  {
                RaspiCam::setAWB(raspicam::RASPICAM_AWB_AUTO);
            };
        break;

        case CV_CAP_PROP_WHITE_BALANCE_BLUE_U:
            if ( value>0 && value<=100 ) {
                float valred=RaspiCam::getAWBG_red();
                RaspiCam::setAWB(raspicam::RASPICAM_AWB_OFF);
                RaspiCam::setAWB_RB(valred, value*100 );
            }
            else  {
                RaspiCam::setAWB(raspicam::RASPICAM_AWB_AUTO);
            };
        break;

//     case CV_CAP_PROP_WHITE_BALANCE :return _camRaspiCam::getAWB();
        default :
            return false;
        };
        return true;

    }
    std::string RaspiCam_Cv::getId() const{
        return RaspiCam::getId();
    }

}
