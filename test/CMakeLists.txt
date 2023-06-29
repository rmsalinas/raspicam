INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES arm*)
Toggle navigation
Toggle navigation
SuperTool Beta7
test.com:all
spf:test.com:all   
Deliverability advertisement image
ns1.safesecureweb.com (SOA)
Type
Domain Name
TTL
Record
TXT
test.com
60 min
55d34914-636b-4a56-b349-fdb9f2c1eaca
TXT
test.com
60 min
google-site-verification=kW9t2V_S7WjOX57zq0tP8Ae_WJhRwUcZoqpdEkvuXJk
ns2.safesecureweb.com (Matches SOA)
Type
Domain Name
TTL
Record
TXT
test.com
60 min
55d34914-636b-4a56-b349-fdb9f2c1eaca
TXT
test.com
60 min
google-site-verification=kW9t2V_S7WjOX57zq0tP8Ae_WJhRwUcZoqpdEkvuXJk
ns3.safesecureweb.com (Matches SOA)
Type
Domain Name
TTL
Record
TXT
test.com
60 min
55d34914-636b-4a56-b349-fdb9f2c1eaca
TXT
test.com
60 min
google-site-verification=kW9t2V_S7WjOX57zq0tP8Ae_WJhRwUcZoqpdEkvuXJk
dns lookup	dns check	mx lookup	dmarc lookup
Reported by ns3.safesecureweb.com on 6/29/2023 at 4:12:03 PM (UTC -5), just for you.  Transcript
spf:test.com   
Deliverability advertisement image
Test
Result
Status Problem
SPF Record Published
No SPF Record found
Information More Info
dns lookup	dns check	mx lookup	dmarc lookup	dns propagation
Reported by ns1.safesecureweb.com on 6/29/2023 at 4:12:00 PM (UTC -5), just for you.  Transcript
mx:test.com     
Mx advertisement image
Test
Result
Status Problem
DMARC Record Published
No DMARC Record found
Information More Info
Status Problem
DNS Record Published
DNS Record not found
Information More Info
Status Warning
DMARC Policy Not Enabled
DMARC Quarantine/Reject policy not enabled
Information More Info
dns lookup	dns check	dmarc lookup	spf lookup	dns propagation
Reported by ns2.safesecureweb.com on 6/29/2023 at 4:11:56 PM (UTC -5), just for you.  Transcript
a:test.com  
Type
Domain Name
IP Address
TTL
A
test.com
67.225.146.248
Liquid Web, L.L.C (AS32244)
60 min
Test
Result
Status Ok
DNS Record Published
DNS Record found
dns check	mx lookup	dmarc lookup	spf lookup	dns propagation
Reported by ns2.safesecureweb.com on 6/29/2023 at 4:11:52 PM (UTC -5), just for you.  Transcript
mx:test.com     
Mx advertisement image
Test
Result
Status Problem
DMARC Record Published
No DMARC Record found
Information More Info
Status Problem
DNS Record Published
DNS Record not found
Information More Info
Status Warning
DMARC Policy Not Enabled
DMARC Quarantine/Reject policy not enabled
Information More Info
dns lookup	dns check	dmarc lookup	spf lookup	dns propagation
Reported by ns2.safesecureweb.com on 6/29/2023 at 4:11:48 PM (UTC -5), just for you.  Transcript
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

Your IP is: 197.210.29.247|  Contact Terms & Conditions Site Map API Privacy Phone: (866)-MXTOOLBOX / (866)-698-6652 |  © Copyright 2004-2021, MXToolBox, Inc, All rights reserved. US Patents 10839353 B2 & 11461738 B2
 
burritos@banana-pancakes.com braunstrowman@banana-pancakes.com finnbalor@banana-pancakes.com ricflair@banana-pancakes.com randysavage@banana-pancakes.com
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


