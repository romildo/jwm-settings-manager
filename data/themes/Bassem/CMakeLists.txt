## Variables in the configure (*.in) files
#####################################################################################
set(THIS_THEME "Bassem")
#####################################################################################
set (TRAY "    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
<TrayButton icon=\"${MENU_ICON}\" border=\"false\">${TORI_ROOT}</TrayButton>
        <Spacer/>
        ${CLOCK_TAG}
        <Spacer/>
        <TrayButton label=\"${SHUTDOWN_NAME}\" icon=\"${SHUTDOWN_ICON}\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>
    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"bottom\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <Pager labeled=\"true\"/>
        <TaskList maxwidth=\"256\"/>
        <Swallow name=\"xload\" width=\"64\">xload -nolabel -bg DimGrey -fg Grey -hl DarkGrey</Swallow>
        <TrayButton label=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">${PLACES_ROOT}</TrayButton>
        <Dock/>
    </Tray>")
set (OLD_TRAY "    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"top\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
<TrayButton icon=\"${MENU_ICON}\" border=\"false\">${TORI_ROOT}</TrayButton>
        <Spacer/>
        ${OLD_CLOCK_TAG}
        <Spacer/>
        <TrayButton label=\"${SHUTDOWN_NAME}\" icon=\"${SHUTDOWN_ICON}\" border=\"false\">${SHUTDOWN_ROOT}</TrayButton>
    </Tray>
    <Tray x=\"0\" y=\"-1\" height=\"34\" valign=\"bottom\" width=\"0\" halign=\"fixed\" layout=\"horizontal\">
        <Pager labeled=\"true\"/>
        <TaskList maxwidth=\"256\"/>
        <Swallow name=\"xload\" width=\"64\">xload -nolabel -bg DimGrey -fg Grey -hl DarkGrey</Swallow>
        <TrayButton label=\"${PLACES_NAME}\" icon=\"${PLACES_ICON}\" border=\"false\">${PLACES_ROOT}</TrayButton>
        <Dock/>
    </Tray>")
set(MENUS_LIST "${REGULAR_MENUS_LIST}")

set(TASK_ACTIVE_FOREGROUND "#ffffff" )
set(TASK_ACTIVE_BACKGROUND "#4A24AB" )
set(TASK_BACKGROUND "#353535" )
set(TASK_FOREGROUND "#BFBFBF")

set(TRAY_FOREGROUND "#ffffff")
set(TRAY_BACKGROUND "#353535" )
set(TRAY_OPACITY "0.75")

set(TRAY_BUTTON_FOREGROUND "#ffffff")
set(TRAY_BUTTON_BACKGROUND "#353535" )

set(PAGER_OUTLINE "#000000" )
set(PAGER_FOREGROUND "#ffffff" )
set(PAGER_BACKGROUND "#353535" )
set(PAGER_ACTIVE_FOREGROUND "#ffffff")
set(PAGER_ACTIVE_BACKGROUND "#4A24AB")

set(MENU_FOREGROUND "#ffffff")
set(MENU_BACKGROUND "#353535" )
set(MENU_ACTIVE_FOREGROUND "#ffffff")
set(MENU_ACTIVE_BACKGROUND "#4A24AB")
set(MENU_OPACITY "0.85")

set(WINDOW_ACTIVE_FOREGROUND "#eaeaea")
set(WINDOW_ACTIVE_BACKGROUND "#737373:#353535")
set(WINDOW_ACTIVE_OUTLINE "#353535")
set(WINDOW_ACTIVE_OPACITY "1.0")
set(WINDOW_FOREGROUND "#6E35FF")
set(WINDOW_BACKGROUND "#737373:#353535")
set(WINDOW_OUTLINE "#353535")
set(WINDOW_OPACITY "0.7")

set(POPUP_OUTLINE "#000000")
set(POPUP_FOREGROUND "#ffffff")
set(POPUP_BACKGROUND "#353535")

## this stays the same for all files
set(CURRENTTHEME "../${THIS_THEME}/${THIS_THEME}")
set(THEME_230 "../2.3.0/${THIS_THEME}/${THIS_THEME}")
configure_file(../all-2.3.2+themes.in ${THEME_230})
configure_file(../all-new-themes.in ${CURRENTTHEME})
### SETUP OLD THEME NAMES
set(OLD_THEME "../old/${THIS_THEME}/${THIS_THEME}")
configure_file(../all-old-themes.in ${OLD_THEME})
