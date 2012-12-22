#ifndef MGSETTINGS_H
#define MGSETTINGS_H

#include <QDialog>
#include <QtGui>

class MGSettings : public QDialog
{
Q_OBJECT

public:
    MGSettings();

protected:
    QDialog *w_dSettingsWindow;
    QVBoxLayout *w_vlTabSettings;
    QTabWidget *w_tabSettings;
        QWidget *w_tab1Display;
            QVBoxLayout *w_vlTabDisplay;
                QGroupBox *w_gbDisplay;
                    QVBoxLayout *w_vlGroupDisplay;
                    QLabel *w_lDisplayPage;
                    QLineEdit *w_leDisplayPage;
                    QHBoxLayout *w_hlDisplayPage;
                    QPushButton *w_pbDefineCurrentPage;

signals:

public slots:

};

#endif // MGSETTINGS_H
