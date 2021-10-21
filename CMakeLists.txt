cmake_minimum_required(VERSION 3.0)

# set the project name
project(hd_interface)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES src/*/*.cc)
add_library(HD_INTERFACE STATIC ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include $ENV{LIBHDDM_HOME}/include $ENV{ROOTSYS}/include $ENV{JANA_HOME}/include $ENV{HDDM_HOME}/include $ENV{DDAQ_HOME}/include $ENV{DMAGNETICFIELDMAP_HOME}/include $ENV{XERCES_INCLUDE} $ENV{HDDS_HOME}/$ENV{BMS_OSNAME}/src $ENV{CCDB_HOME}/include)
install(
  TARGETS HD_INTERFACE
  DESTINATION lib
  )
