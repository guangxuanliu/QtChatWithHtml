#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include "jscontext.h"
#include <QWebChannel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QWebEngineView *m_webView;
    JsContext *m_jsContext;
    QWebChannel *m_webChannel;
};

#endif // WIDGET_H
