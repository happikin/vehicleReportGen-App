cmake_minimum_required(VERSION 2.8)
project(dds-example)
find_package(OpenDDS REQUIRED)

include_directories(
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# IDL TypeSupport Library
add_library(Status_idl)
OPENDDS_TARGET_SOURCES(Status_idl PUBLIC "Status.idl")
target_link_libraries(Status_idl PUBLIC OpenDDS::Dcps)

#setting opendds_lib variable for proper linking
set(opendds_libs
  OpenDDS::Dcps # Core OpenDDS Library
  OpenDDS::InfoRepoDiscovery OpenDDS::Tcp # For run_test.pl
  OpenDDS::Rtps OpenDDS::Rtps_Udp # For run_test.pl --rtps
  Status_idl
)

add_executable(mainsub
    ../src/mainsub.cpp
    ../src/DataReaderListenerImpl.cpp
    ../src/gui/imgui.cpp
    ../src/gui/imgui_draw.cpp
    ../src/gui/imgui_impl_glfw.cpp
    ../src/gui/imgui_impl_opengl3.cpp
    ../src/gui/imgui_tables.cpp
    ../src/gui/imgui_widgets.cpp
    ../src/gui/imgui_demo.cpp
    ../src/gui/implot.cpp
    ../src/gui/implot_items.cpp
    ../src/gui/implot_demo.cpp
)
target_link_libraries(mainsub glfw GL dl ${opendds_libs})


#the following two lines are always required to build and compile a binary
# add_executable(mainsub ../src/mainsub.cpp ../src/DataReaderListenerImpl.cpp)
# target_link_libraries(mainsub ${opendds_libs})

add_executable(RPMpub ../src/RPMpub.cpp)
target_link_libraries(RPMpub ${opendds_libs})

add_executable(EngineTemppub ../src/EngineTemppub.cpp)
target_link_libraries(EngineTemppub ${opendds_libs})

add_executable(CarWeightpub ../src/CarWeightpub.cpp)
target_link_libraries(CarWeightpub ${opendds_libs})

add_executable(FuelStatuspub ../src/FuelStatuspub.cpp)
target_link_libraries(FuelStatuspub ${opendds_libs})

add_executable(SuspensionHealthpub ../src/SuspensionHealthpub.cpp)
target_link_libraries(SuspensionHealthpub ${opendds_libs})