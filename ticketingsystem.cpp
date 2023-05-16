#include "ticketingsystem.h"
#include "ui_ticketingsystem.h"
#include "login.h"
#include <QFile>
#include <QDebug>

TicketingSystem::TicketingSystem(QWidget *parent) :
    ShadowWidget(parent),
    ui(new Ui::TicketingSystem)
{
    ui->setupUi(this);
    // 加载样式表
    QFile file(":/style/style.css");
    file.open(QIODevice::ReadOnly);
    this->setStyleSheet(QString(file.readAll()));
    file.close();
    // 获取数据库实例
    m_db = DBHelper::getInstance();

    ui->stackedWidget_content->setCurrentWidget(ui->page);
}

void TicketingSystem::login()
{
    // 显示登录窗口
    Login *login = new Login();
    login->setAttribute(Qt::WA_DeleteOnClose);
    // 更加返回的loginSuccess信号，判断用户权限
    connect(login, &Login::loginSuccess, [=](User user) {
       this->user = user;
       ui->widget_sideBar->show();
       ui->pushButton_cinemainfo->show();
       ui->pushButton_memManager->show();
       ui->pushButton_movieManager->show();
       //ui->pushButton_sales->show();
       this->show();
    });
    connect(login, &Login::touristVisit, this, &TicketingSystem::show);
    login->show();
}

TicketingSystem::~TicketingSystem()
{
    delete ui;
    m_db->close();
    m_db->deleteLater();
}

// 关闭窗口
void TicketingSystem::on_pushButton_close_clicked()
{
    this->close();
}

// 最大化
void TicketingSystem::on_pushButton_max_clicked()
{
    if (this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }
}

// 最小化
void TicketingSystem::on_pushButton_min_clicked()
{
    this->showMinimized();
}

// 选座购票
void TicketingSystem::on_pushButton_movies_clicked()
{
    ui->stackedWidget_content->setCurrentWidget(ui->page);
}



// 电影管理
void TicketingSystem::on_pushButton_movieManager_clicked()
{
    static bool isLoaded = false;
    ui->stackedWidget_content->setCurrentWidget(ui->page_filmManager);
    if (!isLoaded) {
        ui->page_filmManager->init();
        isLoaded = true;
    }
}

// 用户管理
void TicketingSystem::on_pushButton_memManager_clicked()
{
    static bool isLoaded = false;
    ui->stackedWidget_content->setCurrentWidget(ui->page_userManager);
    if (!isLoaded) {
        ui->page_userManager->init();
        isLoaded = true;
    }
}



void TicketingSystem::on_pushButton_cinemainfo_clicked()
{
    ui->widget_personalInfo->showUserInfo(user);
    ui->stackedWidget_content->setCurrentWidget(ui->page_personalCenter);
}
