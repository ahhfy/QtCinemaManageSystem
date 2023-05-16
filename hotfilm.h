#ifndef HOTFILM_H
#define HOTFILM_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class hotfilm;
}

class hotfilm : public QWidget
{
    Q_OBJECT

public:
    explicit hotfilm(QWidget *parent = nullptr);
    ~hotfilm();

private:
    Ui::hotfilm *ui;
     QSqlTableModel *hot_movieModel = nullptr;
};

#endif // HOTFILM_H
