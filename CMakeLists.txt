CMAKE_MINIMUM_REQUIRED ( VERSION 3.13 )

PROJECT ( umbrella )

SET ( CMAKE_BUILD_TYPE Debug )
SET ( OUTPUT ${CMAKE_PROJECT_NAME} )

SET ( SRC
    src/main.cpp
    src/mysql_handler.cpp
    src/exceptions.cpp
    src/sock_client.cpp
    src/umbrella_handler.cpp
)

SET ( CMAKE_CXX_COMPILER g++)
ADD_COMPILE_OPTIONS ( -g -Wall )

# CMAKE_BUILD_TYPE == Debug
SET ( CMAKE_CXX_FLAGS_DEBUG "-DDEBUG" )

SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )

ADD_EXECUTABLE ( ${OUTPUT} ${SRC} )
TARGET_LINK_LIBRARIES ( ${OUTPUT} mysqlcppconn )
