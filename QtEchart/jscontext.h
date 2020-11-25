#ifndef JSCONTEXT_H
#define JSCONTEXT_H

#include <QObject>
#include <QtDebug>

class JsContext : public QObject
{
    Q_OBJECT
public:
    explicit JsContext();

signals:
    // 向js页面发送消息
    void sendtojsMsg(const QString& msg);
public slots:
    // 接收js页面发送的消息
    void recvjsMsg(const QString& msg);
public slots:
    // 接收main widget 发送的数据
    void recvwidgetMsg(const QString& msg);
};

#endif // JSCONTEXT_H
