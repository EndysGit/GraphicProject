cmake_minimum_required(VERSION 3.8)
project(GraphicProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework OpenGL")

# Linking GLFW lib - responsible for creating window
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS} )


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES
        # Main
        source/src/main.cpp

        # Therd party libs
        # ----------------
        # GLAD - lib that set all OpenGL function pointers
        source/headers/glad.h
        source/headers/khrplatform.h
        source/src/glad.c
        # STB - lib that responsible for loading images
        source/headers/stb_image.h
        source/src/stb_image_implementation.cpp

        # Application parts
        # -----------------
        # Service
        source/headers/ServiceGLEnum.h
        source/src/ServiceGLEnum.cpp
        # Special service part that encapsulate GLAD initialization
        source/headers/my_glad_configure_functions.h
        source/src/my_glad_configure_functions.cpp

        # ??? name it
        # Shader class - encapsulate shaders creation and usages
        source/headers/Shader.h
        source/src/Shader.cpp
        # Texture class - encapsulate texture creation and usages
        source/headers/Texture.h
        source/src/Texture.cpp
        # Vertex type - special type to contain a labaled(attributes) vertex
        source/headers/Vertex.h
        source/src/Vertex.cpp
        # VertexArray class - special stracture to keep information about attributes
        source/headers/VertexArray.h
        source/src/VertexArray.cpp
        # VertexBuffer class - TODO: add information
        source/headers/VertexBuffer.h
        source/src/VertexBuffer.cpp
        )


add_executable(GraphicProject ${SOURCE_FILES})

target_link_libraries(GraphicProject ${GLFW_LIBRARIES} ${OPENGL_LIBRARY} )