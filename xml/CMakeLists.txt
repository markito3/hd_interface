set(MODELS  event rest mc)
set(CLASSES s     r    mc_s)
list(LENGTH MODELS count)
math(EXPR count "${count}-1")
foreach(i RANGE ${count})
  list(GET MODELS ${i} model)
  list(GET CLASSES ${i} class)
  add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/include/hddm_${class}.hpp ${CMAKE_SOURCE_DIR}/src/hddm_${class}++.cpp
    COMMAND hddm-cpp ${CMAKE_CURRENT_SOURCE_DIR}/${model}.xml
    COMMAND cmake -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/hddm_${class}.hpp ${CMAKE_SOURCE_DIR}/include/HDDM/hddm_${class}.hpp
    COMMAND cmake -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/hddm_${class}++.cpp ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_${class}++.cpp
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${model}.xml
    )
  add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/include/hddm_${class}.h ${CMAKE_SOURCE_DIR}/src/hddm_${class}.c
    COMMAND hddm-c ${CMAKE_CURRENT_SOURCE_DIR}/${model}.xml
    COMMAND cmake -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/hddm_${class}.h ${CMAKE_SOURCE_DIR}/include/HDDM/hddm_${class}.h
    COMMAND cmake -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/hddm_${class}.c ${CMAKE_SOURCE_DIR}/src/HDDM/hddm_${class}.c
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${model}.xml
    )
endforeach()
add_custom_target(
  hddm_derived_sources
  DEPENDS
  ${CMAKE_SOURCE_DIR}/include/hddm_s.hpp ${CMAKE_SOURCE_DIR}/include/hddm_r.hpp ${CMAKE_SOURCE_DIR}/include/hddm_mc_s.hpp
  ${CMAKE_SOURCE_DIR}/include/hddm_s.h ${CMAKE_SOURCE_DIR}/include/hddm_r.h ${CMAKE_SOURCE_DIR}/include/hddm_mc_s.h
  )
