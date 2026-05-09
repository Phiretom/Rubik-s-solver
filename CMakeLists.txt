cmake_minimum_required(VERSION 3.28)
project(tryhard)

set(CMAKE_CXX_STANDARD 20)

add_executable(tryhard main.cpp
        cubix.cpp
        cubix.h
        Algorithm.cpp
        TURNS.cpp)

find_package(OpenGL REQUIRED)
target_link_libraries(tryhard PRIVATE ${OPENGL_LIBRARIES})
target_include_directories(tryhard PRIVATE ${OPENGL_INCLUDE_DIR})

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} C:/Users/Fedor/.vcpkg-clion/vcpkgopengl/packages/glew_x64-mingw-dynamic)
find_package(GLEW REQUIRED)
target_link_libraries(tryhard PRIVATE GLEW::GLEW)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} C:/Users/Fedor/.vcpkg-clion/vcpkgopengl/packages/glm_x64-mingw-dynamic)
find_package(glm CONFIG REQUIRED)
target_link_libraries(tryhard PRIVATE glm::glm)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} C:/Users/Fedor/.vcpkg-clion/vcpkgopengl/packages/glfw3_x64-mingw-dynamic)
find_package(GLFW3 REQUIRED)
target_link_libraries(tryhard PRIVATE glfw)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} C:/Users/Fedor/.vcpkg-clion/vcpkgopengl/packages/freeglut_x64-mingw-dynamic)
find_package(GLUT REQUIRED)
target_link_libraries(tryhard PRIVATE GLUT::GLUT)