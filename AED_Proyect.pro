QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    windows/avl_window.cpp \
    windows/binaryheap_window.cpp \
    windows/cola_window.cpp \
    windows/esparza_window.cpp \
    windows/grafo_window.cpp \
    windows/hash_window.cpp \
    windows/lista_window.cpp \
    windows/listadb_window.cpp \
    windows/pila_window.cpp \
    windows/red_black_window.cpp \
    windows/tree_window.cpp

HEADERS += \
    headers/Avl.h \
    headers/BinaryHeap.h \
    headers/Cola.h \
    headers/Esparza.h \
    headers/Grafo.h \
    headers/Hash.h \
    headers/Lista.h \
    headers/ListaDB.h \
    headers/Pila.h \
    headers/Red_black.h \
    headers/Tree.h \
    mainwindow.h \
    windows/avl_window.h \
    windows/binaryheap_window.h \
    windows/cola_window.h \
    windows/esparza_window.h \
    windows/grafo_window.h \
    windows/hash_window.h \
    windows/lista_window.h \
    windows/listadb_window.h \
    windows/pila_window.h \
    windows/red_black_window.h \
    windows/tree_window.h

FORMS += \
    mainwindow.ui \
    windows/avl_window.ui \
    windows/binaryheap_window.ui \
    windows/cola_window.ui \
    windows/esparza_window.ui \
    windows/grafo_window.ui \
    windows/hash_window.ui \
    windows/lista_window.ui \
    windows/listadb_window.ui \
    windows/pila_window.ui \
    windows/red_black_window.ui \
    windows/tree_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
