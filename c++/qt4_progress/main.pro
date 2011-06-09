HEADERS     = mydlgex.hpp \ 
              processthread.hpp \ 
              progressevents.hpp

SOURCES     = main.cpp \
              mydlgex.cpp \
              processthread.cpp \
              progressevents.cpp

FORMS       = mydlgex.ui

UI_DIR = .ui
MOC_DIR = .moc
OBJECTS_DIR = .obj

# install
target.path = main
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources
