#include "restaurant.h"
#include "ui_restaurant.h"

restaurant::restaurant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::restaurant)
{
    ui->setupUi(this);
}

restaurant::~restaurant()
{
    delete ui;
}
