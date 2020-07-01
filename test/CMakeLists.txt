INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES arm*)

FIND_LIBRARY(mmalcore_LIBS NAMES mmal_core PATHS /opt/vc/lib)
FIND_LIBRARY(mmalutil_LIBS NAMES mmal_util PATHS /opt/vc/lib)
FIND_LIBRARY(mmal_LIBS NAMES mmal PATHS /opt/vc/lib)
FIND_LIBRARY(vcos_LIBS NAMES vcos PATHS /opt/vc/lib)
FIND_LIBRARY(bcmhost_LIBS NAMES bcm_host PATHS /opt/vc/lib)


IF( (NOT mmal_LIBS ) OR (NOT mmalutil_LIBS) OR (NOT mmalcore_LIBS) OR (NOT vcos_LIBS) OR (NOT bcmhost_LIBS))
    MESSAGE(FATAL_ERROR "Could not find mmal libraries")
 ENDIF()
 set(REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${mmalcore_LIBS} ${mmalutil_LIBS} ${mmal_LIBS} ${vcos_LIBS} ${bcmhost_LIBS})
 ELSE()
 SET(srcs_base ${srcs_base} private/fake_mmal_dependencies.cpp)
ENDIF()
LINK_LIBRARIES(raspicam ${REQUIRED_LIBRARIES})


IF (OpenCV_FOUND)
ADD_EXECUTABLE(readyuv readyuv.cpp)
target_link_libraries(readyuv ${OpenCV_LIBS})
ENDIF()
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface/vcos" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies")
ADD_EXECUTABLE(raspivid  RaspiCommonSettings.c RaspiPreview.c RaspiVid.c RaspiCamControl.c
    tga.c RaspiCLI.c    RaspiHelpers.c  )
target_compile_options(raspivid PUBLIC "-fpermissive")

ADD_EXECUTABLE(raspicam_yuv  RaspiCommonSettings.c RaspiPreview.c RaspiVidYUV.c RaspiCamControl.c
    tga.c RaspiCLI.c    RaspiHelpers.c  )
target_compile_options(raspicam_yuv PUBLIC "-fpermissive")


