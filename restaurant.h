#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QWidget>

namespace Ui {
class restaurant;
}

class restaurant : public QWidget
{
    Q_OBJECT

public:
    explicit restaurant(QWidget *parent = 0);
    ~restaurant();

private slots:

private:
    Ui::restaurant *ui;
};

#endif // RESTAURANT_H
