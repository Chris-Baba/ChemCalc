cmake_minimum_required(VERSION 3.5)

project(chemcalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets PrintSupport Sql Gui Network Xml KF6Config)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets PrintSupport Sql Gui Network Xml)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(chemcalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mprintdialog.h mprintdialog.cpp mprintdialog.ui
        edit_dialog.h edit_dialog.cpp edit_dialog.ui
        resources.qrc
        select_dialog.h select_dialog.cpp select_dialog.ui
        about_dialog.h about_dialog.cpp about_dialog.ui
        COPYING.txt
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET chemcalc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(chemcalc SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(chemcalc
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(chemcalc PRIVATE Qt${QT_VERSION_MAJOR}::Xml)

# target_link_libraries(chemcalc KF6::ConfigCore KF6::ConfigGui) // Doesn't work.


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.chemcalc)
endif()
set_target_properties(chemcalc PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS chemcalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(chemcalc)
endif()
