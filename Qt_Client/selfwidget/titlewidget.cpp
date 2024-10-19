#include "titlewidget.h"
#include "ui_titlewidget.h"
#include <QMouseEvent>
#include <QDebug>

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleWidget)
{
    ui->setupUi(this);

    m_parent = parent;
    // logo
    ui->logo->setPixmap(QPixmap(":/images/logo.ico").scaled(40, 40));

    // 按钮
    // 最小化
    connect(ui->min_btn, &QToolButton::clicked, [=]()
    {
        m_parent->showMinimized();
    });

    // 关闭
    connect(ui->close_btn, &QToolButton::clicked, [=]()
    {
        emit closeWindow();
    });

    // 设置
    connect(ui->set_btn, &QToolButton::clicked, [=]()
    {
        // 切换到设置窗口
        // 发信号给父窗口
        emit showSetWidget();
    });
}

TitleWidget::~TitleWidget()
{
    delete ui;
}

void TitleWidget::mousePressEvent(QMouseEvent *ev)
{
    // 如果是左键, 计算窗口左上角, 和当前按钮位置的距离
    if(ev->button() == Qt::LeftButton)
    {
        // 计算和窗口左上角的相对位置

        QPointF posF = ev->globalPosition() - m_parent->geometry().topLeft();
        m_pos = posF.toPoint();
    }
}

void TitleWidget::mouseMoveEvent(QMouseEvent *ev)
{
    // 移动是持续的状态, 需要使用buttons
    if(ev->buttons() & Qt::LeftButton)
    {
        QPointF posF = ev->globalPosition() - m_pos;
        QPoint pos = posF.toPoint();
        m_parent->move(pos);
    }
}
