TEMPLATE = app
TARGET= control

include( control.pri )

QT 			+= core widgets network
CONFIG 		+= ordered qwt 
CONFIG 		+= link_pkgconfig silent 
PKGCONFIG 	+= opencv 


QMAKE_CXXFLAGS 	+= -std=c++11 
WARNINGS 		+= -Wall



CONFIG(debug, debug|release) {
    DESTDIR = build/debug
} else {
    DESTDIR = build/release
}

CONFIG(distcc, distcc|local){
	QMAKE_CXX = distcc g++
	QMAKE_CC = distcc gcc
} else {
	QMAKE_CXX = g++
	QMAKE_CC = gcc
}

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
RCC_DIR = share
UI_DIR = form
