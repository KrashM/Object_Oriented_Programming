cmake_minimum_required(VERSION 3.0.0)
project(VehicleWorld VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Vehicles Source/garage.cpp 
                     Source/myString.cpp 
                     Source/utils.cpp 
                     Source/vehicle.cpp 
                     Source/vehicleCollection.cpp 
                     Source/vehicleWorld.cpp)

add_executable(ConsoleApp main.cpp )
target_link_libraries(ConsoleApp Vehicles)

add_executable(UnitTests Tests/garage_Tests.cpp
                         Tests/myString_Tests.cpp
                         Tests/vehicle_Tests.cpp
                         Tests/vehicleCollection_Tests.cpp)
target_link_libraries(UnitTests Vehicles)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
