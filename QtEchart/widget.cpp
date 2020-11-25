#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "9223");
    ui->btnLine->click();

    updatetime = new QTimer(this);
    this->connect(updatetime, SIGNAL(timeout()), this, SLOT(dataupdate()));
    updatetime->start(1000);
    cnt = 0;
    start = 0;

    m_webChannel = new QWebChannel(ui->m_webView->page());
    m_jsContext = new JsContext();
    m_webChannel->registerObject(QStringLiteral("m_jsContext"), m_jsContext);
    ui->m_webView->page()->setWebChannel(m_webChannel);
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath() + "/html/k.html"));
    connect(this, SIGNAL(notityUpdate(const QString&)), m_jsContext, SLOT(recvwidgetMsg(const QString&)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnLine_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/line.html"));
}

void Widget::on_btnLinex_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/linex.html"));
}

void Widget::on_btnLiney_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/liney.html"));
}

void Widget::on_btnBar_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/bar.html"));
}

void Widget::on_btnBarx_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/barx.html"));
}

void Widget::on_btnBary_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/bary.html"));
}

void Widget::on_btnScatter_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/scatter.html"));
}

void Widget::on_btnK_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/k.html"));
}

void Widget::on_btnPie_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/pie.html"));
}

void Widget::on_btnRadar_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/radar.html"));
}

void Widget::on_btnChord_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/chord.html"));
}

void Widget::on_btnGauge_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/gauge.html"));
}

void Widget::on_btnFunnel_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/funnel.html"));
}

void Widget::on_btnData_clicked()
{
    ui->m_webView->load(QUrl("file:///" + qApp->applicationDirPath()+"/html/data.html"));
}


void Widget::on_pushButton_clicked()
{
    //m_content.setSendTextText(ui->lineEdit->text());
}

void Widget::dataupdate()
{
    QString value;
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy/MM/dd hh:mm:ss");
    qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());
    int rand1 = qrand() % 1000;    //产生5以内的随机数
    int rand2 = qrand() % 300;
    QJsonObject json;
    QJsonArray jsonarray = {  "2015/1/24", "2015/1/25", "2015/1/28", "2015/1/29"
                           };
    QJsonArray jsonarray2 ;
//            ={[2320.26,2302.6,2287.3,2362.94],
//                            "[2300,2291.3,2288.26,2308.38]",
//                            "[2295.35,2346.5,2295.35,2346.92]",
//                            "[2190.1,2148.35,2126.22,2190.1]"};
   QJsonArray versionArray0;
    QJsonArray versionArray;
    versionArray.append(2320);
    versionArray.append(2302);
    versionArray.append(2287);
    versionArray.append(2362);

    QJsonArray versionArray3;
    versionArray3.append(2300);
    versionArray3.append(2291);
    versionArray3.append(2288);
    versionArray3.append(2308);

    QJsonArray versionArray4;
    versionArray4.append(2295);
    versionArray4.append(2346);
    versionArray4.append(2295);
    versionArray4.append(2346);

    QJsonArray versionArray5;
    versionArray5.append(2347);
    versionArray5.append(2358);
    versionArray5.append(2337);
    versionArray5.append(2363);

    versionArray0.append(versionArray);
    versionArray0.append(versionArray3);
    versionArray0.append(versionArray4);
    versionArray0.append(versionArray5);
    json.insert("dataX", jsonarray);
    json.insert("seriesData", versionArray0);
    //json.insert("val2", rand2);

    json.insert("time", localTime);
    json.insert("val1", rand1);
    json.insert("val2", rand2);
    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);

    qDebug() << strJson;
    qDebug("cnt=%d",cnt);
    cnt++;
    emit notityUpdate(strJson);
    //updatetime->stop();
}
