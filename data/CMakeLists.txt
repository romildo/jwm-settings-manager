#substitute variables in the desktop file
set(ICON "jwm-settings-manager")
set(EXEC "jwm-settings-manager")
set(NAME "JWM Settings Manager")
# Configure Desktop file
configure_file(${EXEC}.desktop.in ${EXEC}.desktop)

# Make variables for all the desktop files, and icons
FILE(GLOB APPS "*.desktop")
FILE(GLOB ICONS "icons/*.svg")
FILE(GLOB ICONS_PNG "icons/*.png")
FILE(GLOB ICONS_XPM "icons/*.xpm")

# make sure the Cmake list in themes is included
add_subdirectory(themes)

#install themes
install (DIRECTORY themes DESTINATION share/jwm-settings-manager)

#default rox file
install (FILES pb_JWM DESTINATION share/jwm-settings-manager)

# install our icons to pixmaps
install(FILES icons/jwm-settings-manager.png icons/jwm-settings-manager.xpm DESTINATION share/pixmaps)

# install all icons to our own icon directory
install(FILES ${ICONS} DESTINATION usr/share/icons/hicolor/scalable/apps)
install(FILES ${ICONS_PNG} DESTINATION usr/share/icons/hicolor/48x48/apps)
install(FILES ${ICONS_XPM} DESTINATION usr/share/pixmaps)

# install ALL desktop files into /usr/share/applications
install(FILES ${APPS} DESTINATION share/applications)

#install Buttons
install(DIRECTORY Buttons DESTINATION share/jwm-settings-manager)

## clock formats available in a nice list (this is used in the clock config program)
install(FILES time DESTINATION share/jwm-settings-manager)

