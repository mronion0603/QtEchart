#include "jscontext.h"

JsContext::JsContext()
{

}

void JsContext::recvjsMsg(const QString &msg)
{
    //qDebug()<<"recvjs:"<<msg;
}

void JsContext::recvwidgetMsg(const QString& msg)
{
    emit sendtojsMsg(msg);  /* 发送到js页面*/
}
