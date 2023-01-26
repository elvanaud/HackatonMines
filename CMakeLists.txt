cmake_minimum_required(VERSION 3.0.0)
project(Hackator VERSION 0.1.0)

include(CTest)
enable_testing()

set(SFML_DIR "../../../MesDocuments/Informatique/Ordinateur/Programmation/C++/Librairies/SFML/SFML-install/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

add_executable(Hackator main.cc)

target_link_libraries(Hackator sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
