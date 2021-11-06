cmake_minimum_required(VERSION 3.0)

# set the project name
project(hd_interface)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(xml)
file(GLOB SOURCES src/*/*.cc)
set(DERIVED_SOURCES
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_s++.cpp
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_r++.cpp
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_mc_s++.cpp
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_s.c
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_r.c
  ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_mc_s.c
  )
set_source_files_properties(${DERIVED_SOURCES}
                            PROPERTIES GENERATED TRUE)
add_library(HD_INTERFACE STATIC ${SOURCES} ${DERIVED_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/HDDM $ENV{ROOTSYS}/include $ENV{JANA_HOME}/include $ENV{HDDM_HOME}/include $ENV{XERCES_INCLUDE} $ENV{HDDS_HOME}/$ENV{BMS_OSNAME}/src $ENV{CCDB_HOME}/include /usr/include/tirpc)
target_compile_options(
  HD_INTERFACE
  PUBLIC -DHAVE_CCDB -fPIC -pthread -m64
  )
add_dependencies(HD_INTERFACE hddm_derived_sources)
install(
  TARGETS HD_INTERFACE
  DESTINATION lib
  )
