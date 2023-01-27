cmake_minimum_required( VERSION 3.0 )
project(Donjon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(
    -Wall    
    -Wextra  
    -Wshadow  
    -Wnon-virtual-dtor 
    -Wfatal-errors
)

set(SFML_DIR "../../../MesDocuments/Informatique/Ordinateur/Programmation/C++/Librairies/SFML/SFML-install/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

include_directories(include)
add_subdirectory( src )

add_executable(${PROJECT_NAME}.out main.cpp Game.cpp)
target_link_libraries(${PROJECT_NAME}.out  PUBLIC ${PROJECT_NAME} sfml-graphics)
#target_link_libraries(${PROJECT_NAME}.out sfml-graphics)

install(TARGETS ${PROJECT_NAME}.out DESTINATION bin)