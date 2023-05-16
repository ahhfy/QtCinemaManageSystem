#include "hotfilm.h"
#include "ui_hotfilm.h"

hotfilm::hotfilm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hotfilm)
{
    ui->setupUi(this);
    hot_movieModel = new QSqlTableModel(this);
    hot_movieModel->setTable("movie");
    hot_movieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    // 查询user表格所有数据
    hot_movieModel->select();
    // 设置表头，关联数据库字段
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("m_id"),Qt::Horizontal,"id");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("m_name"),Qt::Horizontal,"电影名称");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("picture"),Qt::Horizontal,"图片链接");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("introduce"),Qt::Horizontal,"简介");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("dictors"),Qt::Horizontal,"导演");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("actors"),Qt::Horizontal,"演员");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("durations"),Qt::Horizontal,"时长");
    hot_movieModel->setHeaderData(hot_movieModel->fieldIndex("type"),Qt::Horizontal,"类型");
    // 给tableview设置model
    ui->tableView->setModel(hot_movieModel);
}

hotfilm::~hotfilm()
{
    delete ui;
}
