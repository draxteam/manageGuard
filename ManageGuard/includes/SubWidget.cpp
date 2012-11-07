#include "SubWidget.h"

// Classe AssignItem
AssignItem::AssignItem()
{
     w_lAssign = new QLabel("Assigné dans Caserne1");
     w_pbDelAssign = new QPushButton(QIcon("icons/del.png"), "");
         w_pbDelAssign->setStyleSheet("QPushButton {background:0; border:0; height:15px; max-width:15px;}");
         w_pbDelAssign->setIconSize(QSize(10, 10));

     w_hlAssignBox = new QHBoxLayout;
     w_hlAssignBox->addWidget(w_lAssign);
     w_hlAssignBox->addWidget(w_pbDelAssign);

     setLayout(w_hlAssignBox);
}
