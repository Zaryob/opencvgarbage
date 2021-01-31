cmake_minimum_required(VERSION 3.0)
project(FaceDetector LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/FaceDetector.cpp src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# OpenCV setup
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Introduce preprocessor variables to keep paths of asset files
set(FACE_DETECTION_CONFIGURATION "${PROJECT_SOURCE_DIR}/assets/deploy.prototxt")
set(FACE_DETECTION_WEIGHTS "${PROJECT_SOURCE_DIR}/assets/deploy.caffemodel")

target_compile_definitions(${PROJECT_NAME} PRIVATE FACE_DETECTION_CONFIGURATION="${FACE_DETECTION_CONFIGURATION}")
target_compile_definitions(${PROJECT_NAME} PRIVATE FACE_DETECTION_WEIGHTS="${FACE_DETECTION_WEIGHTS}")

