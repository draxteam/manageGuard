#include "SubWidget.h"

// Classe AssignItem
AssignItem::AssignItem()
{
}

AssignItem::~AssignItem()
{
    delete w_hlAssignBox;
}

void AssignItem::createRow(int rowNb)
{
    a_Nb = rowNb;
    w_lAssign = new QLabel("Assigné dans la caserne " + QString::number(rowNb));
    w_pbDelAssign = new QPushButton;
        w_pbDelAssign->setIcon(QIcon("icons/del.png"));
        w_pbDelAssign->setStyleSheet("QPushButton {background:0; border:0; height:15px; max-width:15px;}");
        w_pbDelAssign->setIconSize(QSize(12, 12));
        connect(w_pbDelAssign, SIGNAL(clicked()), this, SLOT(sl_removeAssignRow()));

    w_hlAssignBox = new QHBoxLayout;
    w_hlAssignBox->addWidget(w_lAssign);
    w_hlAssignBox->addWidget(w_pbDelAssign);

    setLayout(w_hlAssignBox);
}

void AssignItem::sl_removeAssignRow()
{
    emit si_removeAssignRow(a_Nb);
}
