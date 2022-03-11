# CMakeList.txt : CMake project for BugReportingTool, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(performance)

set( DCMAKE_TOOLCHAIN_FILE "D:/Code/vcpkg/Microsoft/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Boost 1.77.0 COMPONENTS filesystem thread system)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set ( CXX_SRCS
	StatusTool.cpp
	MainWindow.cpp
	#performance/widgets/ramwidget.cpp
	#performance/dataQuery/queryresource.cpp
	#performance/dataQuery/dataquery.cpp
	#performance/dataQuery/ramdataquery.cpp

)

include_directories(
	"D:/Code/vcpkg/Microsoft/vcpkg/installed/x64-windows/include/qt5"
	"D:/Code/vcpkg/Microsoft/vcpkg/installed/x64-windows/include/boost"
)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${CXX_SRCS})

# TODO: Add tests and install targets if needed.
target_link_libraries( ${PROJECT_NAME}
	Qt5::Core
	Qt5::Widgets
)
