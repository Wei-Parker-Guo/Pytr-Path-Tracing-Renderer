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
  ${CMAKE_SOURCE_DIR}/Ultralight/include
#  ${FREETYPE_INCLUDE_DIRS} disabled freetype since it causes malfunc on my Win10 system
)

#-------------------------------------------------------------------------------
# Set link directories
#-------------------------------------------------------------------------------
link_directories(
  ${GLEW_LIBRARY_DIRS}
  ${GLFW_LIBRARY_DIRS}
  ${ASSIMP_LIBRARY_DIRS}
  ${CMAKE_SOURCE_DIR}/Ultralight/lib
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
    Ultralight ${ULTRALIGHT_LIBRARIES}
    AppCore ${ULTRALIGHT_LIBRARIES}
    UltralightCore ${ULTRALIGHT_LIBRARIES}
    WebCore ${ULTRALIGHT_LIBRARIES}
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

if (APPLE)
  # Enable High-DPI on macOS through our custom Info.plist template
  set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in) 
endif()

if (MSVC)
  # Tell MSVC to use main instead of WinMain for Windows subsystem executables
  set_target_properties(${APP_NAME} PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")
endif()

# Put executable in build directory root
set(EXECUTABLE_OUTPUT_PATH ..)

# Install to project root
install(TARGETS pytr DESTINATION ${PYTR_SOURCE_DIR})

# Copy all binaries to target directory
add_custom_command(TARGET pytr POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Ultralight/bin ${CMAKE_SOURCE_DIR}/out/build)  

