# Project Needs a name ofcourse
project(plasma-wattrate)
 
# Find the required Libaries
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
 
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )
 
# We add our source code here
set(wattrate_SRCS upowerhandler.cpp wattrate.cpp)
 

set_property(SOURCE upower.xml PROPERTY NO_NAMESPACE TRUE)
set_property(SOURCE upowerdev.xml PROPERTY NO_NAMESPACE TRUE)
set_property(SOURCE upowerdev.xml PROPERTY INCLUDE "upowerhandler.h")
QT4_ADD_DBUS_INTERFACE(wattrate_SRCS upower.xml upower)
QT4_ADD_DBUS_INTERFACE(wattrate_SRCS upowerdev.xml upowerdevices)

# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_wattrate ${wattrate_SRCS})
target_link_libraries(plasma_applet_wattrate 
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})
 
install(TARGETS plasma_applet_wattrate
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-wattrate.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
