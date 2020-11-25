QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets webchannel

TARGET = QtEchartDemo
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp\
        jscontext.cpp
HEADERS  += widget.h  \
        jscontext.h
FORMS    += widget.ui

DISTFILES += \
    qwebchannel.js
INCLUDEPATH += "C:/Program Files (x86)/Microsoft Visual Studio/2017/BuildTools/VC/Tools/MSVC/14.10.25017/lib"
LIBS += -L"C:/Program Files (x86)/Microsoft Visual Studio/2017/BuildTools/VC/Tools/MSVC/14.10.25017/lib/x64"

CONFIG(debug, debug|release) {
  #设置debug配置下编译生成文件的路径
  TARGET = $$join(TARGET,,,d)   #为debug版本生成的文件增加d的后缀
  contains(TEMPLATE, "lib") {
    DESTDIR = $$PWD/Bin        #将库放在当前工程的Bin文件夹下
    DLLDESTDIR = $$PWD/Bin    #将动态库放在当前工程的Bin文件夹下
  } else {
    DESTDIR = $$PWD/Bin        #将应用程序放在当前工程的Bin文件夹下
  }
  OBJECTS_DIR = ./debug/obj     #将生成的对象文件放在专门的obj文件夹下
  MOC_DIR = ./debug/moc         #将QT自动生成的对象放在moc文件夹下
} else {
  #设置release配置下编译生成文件的路径
  contains(TEMPLATE, "lib") {
    DESTDIR = $$PWD/Bin        #将库放在当前工程的Bin文件夹下
    DLLDESTDIR = $$PWD/Bin     #将动态库放在当前工程的Bin文件夹下
  } else {
    DESTDIR = $$PWD/Bin        #将应用程序放在当前工程的Bin文件夹下
  }
  OBJECTS_DIR = ./release/obj   #将生成的对象文件放在专门的obj文件夹下
  MOC_DIR = ./release/moc       #将QT自动生成的对象放在moc文件夹下
}
