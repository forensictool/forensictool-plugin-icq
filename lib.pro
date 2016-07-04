include(version.pri)

TEMPLATE = lib
TARGET = forensictool-plugin-icq
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

SOURCES += \
	src/lib.cpp \
	src/task.cpp\
	src/writerMessages.cpp\
	src/XMLReader_ICQContacts.cpp \


HEADERS += \
	src/lib.h \
	src/task.h\
	src/writerMessages.h\
	src/XMLReader_ICQContacts.h \
