cmake_minimum_required(VERSION 3.28)
project(RubiksSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(rubiks_solver main.cpp
        cubix.cpp
        cubix.h
        Algorithm.cpp
        TURNS.cpp)

# Зависимости ищутся стандартным find_package.
# Установите библиотеки через системный пакетный менеджер или vcpkg и при конфигурации CMake укажите, например:
#   -DCMAKE_TOOLCHAIN_FILE=<путь>/vcpkg/scripts/buildsystems/vcpkg.cmake
# Либо задайте CMAKE_PREFIX_PATH в окружении / настройках IDE — без абсолютных путей в этом файле.

find_package(OpenGL REQUIRED)
target_link_libraries(rubiks_solver PRIVATE ${OPENGL_LIBRARIES})
target_include_directories(rubiks_solver PRIVATE ${OPENGL_INCLUDE_DIR})

find_package(GLEW REQUIRED)
target_link_libraries(rubiks_solver PRIVATE GLEW::GLEW)

find_package(glm CONFIG REQUIRED)
target_link_libraries(rubiks_solver PRIVATE glm::glm)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(rubiks_solver PRIVATE glfw)

find_package(GLUT REQUIRED)
target_link_libraries(rubiks_solver PRIVATE GLUT::GLUT)
