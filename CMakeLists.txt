# Project Needs a name ofcourse
project(plasma-batteryconsumption)
 
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
set(batteryconsumption_SRCS upowerhandler.cpp batteryconsumption.cpp)
 

set_property(SOURCE upower.xml PROPERTY NO_NAMESPACE TRUE)
set_property(SOURCE upowerdev.xml PROPERTY NO_NAMESPACE TRUE)
set_property(SOURCE upowerdev.xml PROPERTY INCLUDE "upowerhandler.h")
QT4_ADD_DBUS_INTERFACE(batteryconsumption_SRCS upower.xml upower)
QT4_ADD_DBUS_INTERFACE(batteryconsumption_SRCS upowerdev.xml upowerdevices)

# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_batteryconsumption ${batteryconsumption})
target_link_libraries(plasma_applet_batteryconsumption 
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})
 
install(TARGETS plasma_applet_batteryconsumption
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-batteryconsumption.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
