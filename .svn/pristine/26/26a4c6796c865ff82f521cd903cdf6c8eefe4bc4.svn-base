INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_LIBRARIES(raspicam )




#ADD_EXECUTABLE(RaspiStill RaspiStill.c)

ADD_EXECUTABLE(raspicam_test raspicam_test.cpp )
INSTALL(TARGETS raspicam_test   RUNTIME DESTINATION bin)
 
ADD_EXECUTABLE(raspicam_still_test raspicam_still_test.cpp )
INSTALL(TARGETS raspicam_still_test   RUNTIME DESTINATION bin)

IF (OpenCV_FOUND)
ADD_EXECUTABLE(raspicam_cv_test raspicam_cv_test.cpp )
target_link_libraries(raspicam_cv_test   opencv_core  opencv_imgcodecs raspicam_cv )

ADD_EXECUTABLE(raspicam_cv_still_test raspicam_cv_still_test.cpp )
target_link_libraries(raspicam_cv_still_test opencv_core   opencv_imgcodecs raspicam_cv )

INSTALL(TARGETS raspicam_cv_test  raspicam_cv_still_test RUNTIME DESTINATION bin)

ENDIF()
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface/vcos" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies")


