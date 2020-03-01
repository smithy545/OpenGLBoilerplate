cmake_minimum_required(VERSION 3.15)
project(worker)

set(CMAKE_CXX_STANDARD 14)


find_package(OpenGL REQUIRED)

# Compile external dependencies
add_subdirectory (external)

include_directories(
        external/glfw-3.1.2/include
        external/glm
        external/glew-1.13.0/include
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)


# add exec
add_executable(worker src/main.cpp src/Renderer.cpp src/Renderer.h src/Humoid.cpp src/Humoid.h src/Camera.cpp src/Camera.h src/Mesh.h src/MeshObject.h src/MeshUtil.cpp src/MeshUtil.h src/TerrainMap.cpp src/TerrainMap.h)
target_link_libraries(worker
        ${ALL_LIBS}
        )
