cmake_minimum_required(VERSION 3.16)

project(MediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FFMPEG_HOME "D:/ffmpeg-7.1.1-full_build-shared")
include_directories(${FFMPEG_HOME}/include)
link_directories(${FFMPEG_HOME}/lib)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)
find_package(Qt6 REQUIRED COMPONENTS MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MediaPlayer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        image/next.png image/play.png image/prev.png image/random.png image/stop.png
        image/image.qrc
        MediaWidget.h
        MediaWidget.cpp
        ButtonWidget.h
        ButtonWidget.cpp
        VolumeWidget.h
        VolumeWidget.cpp
        MainWidget.h
        MainWidget.cpp
        ListWidget.h
        ListWidget.cpp
        ProgressBarWidget.h
        ProgressBarWidget.cpp
        VideoContainer.h
        VideoContainer.cpp
        image/speed.png
        RateWidget.h
        RateWidget.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MediaPlayer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MediaPlayer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MediaPlayer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MediaPlayer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MediaPlayer PRIVATE Qt6::Gui)
target_link_libraries(MediaPlayer PRIVATE Qt6::Multimedia)
target_link_libraries(MediaPlayer PRIVATE Qt6::MultimediaWidgets)
target_link_libraries(MediaPlayer PRIVATE Qt6::Core)
target_link_libraries(MediaPlayer PRIVATE ${FFMPEG_LIBS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MediaPlayer)
endif()
set_target_properties(MediaPlayer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MediaPlayer)
endif()
