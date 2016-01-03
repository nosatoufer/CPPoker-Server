/********************************************************************************
** Form generated from reading UI file 'pokerservergui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKERSERVERGUI_H
#define UI_POKERSERVERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PokerServerGui
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *logs;
    QLineEdit *commandLine;
    QPushButton *buttonSend;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *PokerServerGui)
    {
        if (PokerServerGui->objectName().isEmpty())
            PokerServerGui->setObjectName(QStringLiteral("PokerServerGui"));
        PokerServerGui->setEnabled(true);
        PokerServerGui->resize(401, 302);
        actionQuitter = new QAction(PokerServerGui);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(PokerServerGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        logs = new QTextEdit(centralWidget);
        logs->setObjectName(QStringLiteral("logs"));
        logs->setEnabled(true);
        logs->setReadOnly(true);

        gridLayout->addWidget(logs, 0, 0, 1, 2);

        commandLine = new QLineEdit(centralWidget);
        commandLine->setObjectName(QStringLiteral("commandLine"));

        gridLayout->addWidget(commandLine, 1, 0, 1, 1);

        buttonSend = new QPushButton(centralWidget);
        buttonSend->setObjectName(QStringLiteral("buttonSend"));

        gridLayout->addWidget(buttonSend, 1, 1, 1, 1);

        PokerServerGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PokerServerGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 24));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        PokerServerGui->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);

        retranslateUi(PokerServerGui);

        QMetaObject::connectSlotsByName(PokerServerGui);
    } // setupUi

    void retranslateUi(QMainWindow *PokerServerGui)
    {
        PokerServerGui->setWindowTitle(QApplication::translate("PokerServerGui", "Poker - Serveur", 0));
        actionQuitter->setText(QApplication::translate("PokerServerGui", "Quitter", 0));
        buttonSend->setText(QApplication::translate("PokerServerGui", "Ex\303\251cuter", 0));
        menuMenu->setTitle(QApplication::translate("PokerServerGui", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class PokerServerGui: public Ui_PokerServerGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKERSERVERGUI_H
