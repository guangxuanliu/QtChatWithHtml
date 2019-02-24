#include "widget.h"
#include "ui_widget.h"
#include <QStackedLayout>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //加载Web页面
    m_webView = new QWebEngineView(this);
    QStackedLayout *layout = new QStackedLayout(ui->frame);
    ui->frame->setLayout(layout);
    layout->addWidget(m_webView);

    QString localFileName = QDir::currentPath() + QDir::separator() + "html" + QDir::separator() + "index.html";
    m_webView->load(QUrl::fromLocalFile(localFileName));

    //通信部分
    m_jsContext = new JsContext(this);
    m_webChannel = new QWebChannel(this);
    m_webChannel->registerObject("context",m_jsContext);
    m_webView->page()->setWebChannel(m_webChannel);
    connect(m_jsContext,&JsContext::recvdMsg,this,[this](const QString& msg){
        ui->textEdit->append("Web say : " + msg);
    });

    connect(ui->btnSend,&QPushButton::clicked,this,[this](){
        QString msg = ui->lineEdit->text();
        if(!msg.isEmpty())
        {
            m_jsContext->sendMsg(m_webView->page(),msg);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
