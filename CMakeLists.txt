cmake_minimum_required(VERSION 2.8)
project(ADAS_Service)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

#include(FindPkgConfig)
#find_package(CommonAPI 3.1.6 REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
#find_package(CommonAPI-DBus 3.1.6 REQUIRED CONFIG NO_SYSTEM_ENVIRONMENT_PATH NO_CMAKE_SYSTEM_PATH)
#find_package(CommonAPI-SomeIP 3.1.6 REQUIRED)
find_package(vsomeip3)
#pkg_check_modules(DBus REQUIRED dbus-1>=1.4)

include_directories(
    src-gen/core/ADAS_SystStatus/common
    src-gen/core/ADAS_SystStatus/proxy
    src-gen/core/ADAS_SystStatus/stub
    src-gen/core/ADAS_SystStatus/skel
    src-gen/someip/ADAS_SystStatus/common
    src-gen/someip/ADAS_SystStatus/proxy
    src-gen/someip/ADAS_SystStatus/stub

    src-gen/core/FCS_SLIF_IHBC_Status/common
    src-gen/core/FCS_SLIF_IHBC_Status/proxy
    src-gen/core/FCS_SLIF_IHBC_Status/stub
    src-gen/core/FCS_SLIF_IHBC_Status/skel
    src-gen/someip/FCS_SLIF_IHBC_Status/common
    src-gen/someip/FCS_SLIF_IHBC_Status/proxy
    src-gen/someip/FCS_SLIF_IHBC_Status/stub

    #src-gen/core
    #src-gen/someip
	D:/workspace/commonapicxx/capicxx-core-runtime/include
	D:/workspace/commonapicxx/capicxx-someip-runtime/include
	D:/workspace/vsomeip-src/3-1-20-3/vsomeip/interface
)

link_directories(
    D:/workspace/commonapicxx/capicxx-core-runtime/build
	D:/workspace/commonapicxx/capicxx-someip-runtime/build
	#D:/workspace/vsomeip-src/3-1-20-3/vsomeip/build-31-174
	
    #${DBus_INCLUDE_DIRS}/dbus/.libs
)

#FILE(GLOB_RECURSE AdasSysStatus_SKEL_LIB_SRCS src-gen/core/skel/*.cpp)
#add_library(AdasSysStatusskel SHARED ${AdasSysStatus_SKEL_LIB_SRCS})
#target_link_libraries(AdasSysStatusskel)

FILE(GLOB_RECURSE AdasSysStatus_SOMEIP_COMMON_LIB_SRCS src-gen/someip/ADAS_SystStatus/common/*.cpp)
add_library(AdasSysStatussomeipcommon SHARED ${AdasSysStatus_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(AdasSysStatussomeipcommon CommonAPI CommonAPI-SomeIP vsomeip3)

FILE(GLOB_RECURSE AdasSysStatus_SOMEIP_PROXY_LIB_SRCS src-gen/someip/ADAS_SystStatus/proxy/*.cpp)
add_library(AdasSysStatussomeipproxy SHARED ${AdasSysStatus_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(AdasSysStatussomeipproxy CommonAPI CommonAPI-SomeIP vsomeip3)

FILE(GLOB_RECURSE AdasSysStatus_SOMEIP_STUB_LIB_SRCS src-gen/someip/ADAS_SystStatus/stub/*.cpp)
add_library(AdasSysStatussomeipstub SHARED ${AdasSysStatus_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(AdasSysStatussomeipstub CommonAPI CommonAPI-SomeIP vsomeip3)

FILE(GLOB_RECURSE FCS_SLIF_IHBC_Status_SOMEIP_COMMON_LIB_SRCS src-gen/someip/FCS_SLIF_IHBC_Status/common/*.cpp)
add_library(FCS_SLIF_IHBC_Statussomeipcommon SHARED ${AdasSysStatus_SOMEIP_COMMON_LIB_SRCS})
target_link_libraries(FCS_SLIF_IHBC_Statussomeipcommon CommonAPI CommonAPI-SomeIP vsomeip3)

FILE(GLOB_RECURSE FCS_SLIF_IHBC_Status_SOMEIP_PROXY_LIB_SRCS src-gen/someip/FCS_SLIF_IHBC_Status/proxy/*.cpp)
add_library(FCS_SLIF_IHBC_Statussomeipproxy SHARED ${AdasSysStatus_SOMEIP_PROXY_LIB_SRCS})
target_link_libraries(FCS_SLIF_IHBC_Statussomeipproxy CommonAPI CommonAPI-SomeIP vsomeip3)

FILE(GLOB_RECURSE FCS_SLIF_IHBC_Status_SOMEIP_STUB_LIB_SRCS src-gen/someip/FCS_SLIF_IHBC_Status/stub/*.cpp)
add_library(FCS_SLIF_IHBC_Statussomeipstub SHARED ${AdasSysStatus_SOMEIP_STUB_LIB_SRCS})
target_link_libraries(FCS_SLIF_IHBC_Statussomeipstub CommonAPI CommonAPI-SomeIP vsomeip3)


#add_executable(AdasServiceClient src/AdasSysStatusClient.cpp)
#target_link_libraries(AdasServiceClient CommonAPI  Adassomeipproxy Adassomeipcommon CommonAPI-SomeIP vsomeip3)

#add_executable(AdasServiceService src/AdasSysStatusService.cpp)
#target_link_libraries(AdasServiceService CommonAPI Adassomeipstub Adassomeipcommon CommonAPI-SomeIP vsomeip3)

add_executable(AdasServiceClient src/AdasSysStatusClient.cpp)
target_link_libraries(AdasServiceClient CommonAPI  AdasSysStatussomeipproxy AdasSysStatussomeipcommon FCS_SLIF_IHBC_Statussomeipproxy FCS_SLIF_IHBC_Statussomeipcommon CommonAPI-SomeIP vsomeip3)

add_executable(AdasServiceService src/AdasSysStatusService.cpp)
target_link_libraries(AdasServiceService CommonAPI AdasSysStatussomeipstub AdasSysStatussomeipcommon  FCS_SLIF_IHBC_Statussomeipstub FCS_SLIF_IHBC_Statussomeipcommon  CommonAPI-SomeIP vsomeip3)