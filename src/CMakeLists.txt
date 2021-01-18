add_executable(app "main.cpp" "sphere.cpp" "scene.cpp" "camera.cpp")

target_compile_features(app PRIVATE cxx_std_17)

target_include_directories(app PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/extern/glm"
    "${CMAKE_SOURCE_DIR}/extern/fmt/include"
)