

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES arm*) 

FIND_LIBRARY(mmalcore_LIBS NAMES mmal_core PATHS /opt/vc/lib)
FIND_LIBRARY(mmalutil_LIBS NAMES mmal_util PATHS /opt/vc/lib)
FIND_LIBRARY(mmal_LIBS NAMES mmal PATHS /opt/vc/lib)
IF( (NOT mmal_LIBS ) OR (NOT mmalutil_LIBS) OR (NOT mmalcore_LIBS) )
    MESSAGE(FATAL_ERROR "Could not find mmal libraries")
 ENDIF()
 set(REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${mmalcore_LIBS} ${mmalutil_LIBS} ${mmal_LIBS}  )
 ELSE()
 SET(srcs_base ${srcs_base} private/fake_mmal_dependencies.cpp)
ENDIF()
 include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface/vcos" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/interface" "${CMAKE_CURRENT_SOURCE_DIR}/../dependencies")



INCLUDE_DIRECTORIES(.)
SET(private_hdrs_base "private/private_types.h  private/private_impl.h exceptions.h private/threadcondition.h ")
SET(private_still_hdrs_base "private_still/private_still_types.h  private/private_still_impl.h")

SET(public_hdrs_base raspicamtypes.h raspicam.h raspicam_still.h cvversioning.h)
SET(srcs_base ${public_hdrs_base} ${srcs_base} raspicam.cpp raspicam_still.cpp  private/private_impl.cpp private/threadcondition.cpp  private_still/private_still_impl.cpp)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )

ADD_LIBRARY(raspicam ${hdrs_base} ${srcs_base} )
SET_TARGET_PROPERTIES(raspicam PROPERTIES 				# create *nix style library versions + symbolic links
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_SOVERSION}
	CLEAN_DIRECT_OUTPUT 1 										# allow creating static and shared libs without conflicts
        OUTPUT_NAME "raspicam${PROJECT_DLLVERSION}" 	# avoid conflicts between library and binary target names
)
TARGET_LINK_LIBRARIES(raspicam  ${REQUIRED_LIBRARIES}  )
INSTALL(TARGETS raspicam
	RUNTIME DESTINATION bin COMPONENT main
	LIBRARY DESTINATION lib PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE COMPONENT main
	ARCHIVE DESTINATION lib COMPONENT main)


#Add opencv component if required
#Opencv Lib	
IF (${OpenCV_FOUND})
    message(STATUS "Adding cv library")
    SET(hdrs_cv raspicam_cv.h raspicam_still_cv.h)
    SET(srcs_cv raspicam_cv.cpp raspicam_still_cv.cpp)
    ADD_LIBRARY(raspicam_cv ${hdrs_cv} ${srcs_cv} )
    SET_TARGET_PROPERTIES(raspicam_cv PROPERTIES 				# create *nix style library versions + symbolic links
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_SOVERSION}
	CLEAN_DIRECT_OUTPUT 1 										# allow creating static and shared libs without conflicts
        OUTPUT_NAME "raspicam_cv${PROJECT_DLLVERSION}" 	# avoid conflicts between library and binary target names
    )
    TARGET_LINK_LIBRARIES(raspicam_cv  raspicam ${REQUIRED_LIBRARIES}  opencv_core )

    INSTALL(TARGETS raspicam_cv
	RUNTIME DESTINATION bin COMPONENT main
	LIBRARY DESTINATION lib PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE COMPONENT main
	ARCHIVE DESTINATION lib COMPONENT main)
ENDIF()
	
	
#Installation of all header files	
INSTALL(FILES ${public_hdrs_base} ${hdrs_cv}
        DESTINATION include/raspicam
	COMPONENT main)

