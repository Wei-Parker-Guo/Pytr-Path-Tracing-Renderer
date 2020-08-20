cmake_minimum_required(VERSION 2.8)

# Application source

set(PYTR_CPU_SOURCE
    "shaders/sketch_shader.cpp"
    "shaders/translucent_shader.cpp"
    "shaders/layered_toon_shader.cpp"
    "shaders/basic_shaders.cpp"
    fast_math.cpp
    main.cpp
)

#-------------------------------------------------------------------------------
# Set include directories
#-------------------------------------------------------------------------------
include_directories(
  ${GLEW_INCLUDE_DIRS}
  ${GLFW_INCLUDE_DIRS}
  ${ASSIMP_INCLUDE_DIRS}
#  ${FREETYPE_INCLUDE_DIRS} disabled freetype since it causes malfunc on my Win10 system
)

#-------------------------------------------------------------------------------
# Set link directories
#-------------------------------------------------------------------------------
link_directories(
  ${GLEW_LIBRARY_DIRS}
  ${GLFW_LIBRARY_DIRS}
  ${ASSIMP_LIBRARY_DIRS}
#  ${CGL_LIBRARY_DIRS}
#  ${FREETYPE_LIBRARY_DIRS}
)

#-------------------------------------------------------------------------------
# Add executable
#-------------------------------------------------------------------------------

add_executable(pytr ${PYTR_CPU_SOURCE})

target_link_libraries( pytr
    glew ${GLEW_LIBRARIES}
    glfw ${GLFW_LIBRARIES}
    assimp ${ASSIMP_LIBRARIES}
    ${OPENGL_LIBRARIES}
#    ${FREETYPE_LIBRARIES}
    ${CMAKE_THREADS_INIT}
)

#-------------------------------------------------------------------------------
# Platform-specific configurations for target
#-------------------------------------------------------------------------------
if(APPLE)
  set_property( TARGET pytr APPEND_STRING PROPERTY COMPILE_FLAGS
                "-Wno-deprecated-declarations -Wno-c++11-extensions")
endif(APPLE)

# Put executable in build directory root
set(EXECUTABLE_OUTPUT_PATH ..)

# Install to project root
install(TARGETS pytr DESTINATION ${PYTR_SOURCE_DIR})
