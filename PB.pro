SOURCES += \
    main.cpp \
    PassportBalanceManager.cpp \
    MainWindow.cpp \
    LoggerWidget.cpp \
    TableManager.cpp

QMAKE_CXXFLAGS += -std=c++11

QT      += \
    widgets \
    xml

HEADERS += \
    MissionFabric.h \
    PassportBalanceManager.h \
    MainWindow.h \
    LoggerWidget.h \
    PBDefines.h \
    TableManager.h \
    CustomWidgets.h

RESOURCES += \
    icons.qrc
