include(version.pri)

TEMPLATE = app
TARGET = forensictool-icq
DESTDIR = bin/
OBJECTS_DIR = tmp/
QT -= gui
QT += sql
CONFIG += dll

INCLUDEPATH += src/forensictool-core/v0.3.1/interfaces/

SOURCES += \
	src/app.cpp \
	src/task.cpp \
	src/writerMessages.cpp \
	src/XMLReader_ICQContacts.cpp \
	src/forensictool-core/v0.3.1/helpers/config.cpp \
	src/forensictool-core/v0.3.1/helpers/typeos.cpp \


HEADERS += \
	src/task.h \
	src/writerMessages.h \
	src/XMLReader_ICQContacts.h \
	src/forensictool-core/v0.3.1/helpers/config.h \
	src/forensictool-core/v0.3.1/helpers/typeos.h \
	


