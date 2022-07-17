cmake_minimum_required(VERSION 3.21)
project(PlayWithFire)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Multimedia
        Widgets
        REQUIRED)

add_executable(PlayWithFire main.cpp src/windows/Home.cpp src/windows/Home.h src/view/TextField.cpp src/view/TextField.h resources.qrc src/view/Label.cpp src/view/Label.h src/view/Button.cpp src/view/Button.h src/windows/Game.cpp src/windows/Game.h src/view/Box.cpp src/view/Box.h src/view/Wall.cpp src/view/Wall.h src/view/Character.cpp src/view/Character.h src/view/Bomb.cpp src/view/Bomb.h src/view/Empty.cpp src/view/Empty.h src/view/Block.cpp src/view/Block.h src/windows/Scoreboard.cpp src/windows/Scoreboard.h)
target_link_libraries(PlayWithFire
        Qt6::Core
        Qt6::Gui
        Qt6::Multimedia
        Qt6::Widgets
        )

if (WIN32)

    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
