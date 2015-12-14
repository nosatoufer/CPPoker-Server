/********************************************************************************
** Form generated from reading UI file 'pokerserveurgui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKERSERVEURGUI_H
#define UI_POKERSERVEURGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PokerServeurGui
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QTextEdit *logs;
    QLineEdit *commandLine;
    QPushButton *buttonSend;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *PokerServeurGui)
    {
        if (PokerServeurGui->objectName().isEmpty())
            PokerServeurGui->setObjectName(QStringLiteral("PokerServeurGui"));
        PokerServeurGui->setEnabled(true);
        PokerServeurGui->resize(401, 302);
        actionQuitter = new QAction(PokerServeurGui);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(PokerServeurGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logs = new QTextEdit(centralWidget);
        logs->setObjectName(QStringLiteral("logs"));
        logs->setEnabled(true);
        logs->setGeometry(QRect(10, 10, 381, 231));
        logs->setReadOnly(true);
        commandLine = new QLineEdit(centralWidget);
        commandLine->setObjectName(QStringLiteral("commandLine"));
        commandLine->setGeometry(QRect(10, 250, 301, 20));
        buttonSend = new QPushButton(centralWidget);
        buttonSend->setObjectName(QStringLiteral("buttonSend"));
        buttonSend->setGeometry(QRect(320, 250, 75, 23));
        PokerServeurGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PokerServeurGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        PokerServeurGui->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);

        retranslateUi(PokerServeurGui);

        QMetaObject::connectSlotsByName(PokerServeurGui);
    } // setupUi

    void retranslateUi(QMainWindow *PokerServeurGui)
    {
        PokerServeurGui->setWindowTitle(QApplication::translate("PokerServeurGui", "Poker - Serveur", 0));
        actionQuitter->setText(QApplication::translate("PokerServeurGui", "Quitter", 0));
        buttonSend->setText(QApplication::translate("PokerServeurGui", "Ex\303\251cuter", 0));
        menuMenu->setTitle(QApplication::translate("PokerServeurGui", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class PokerServeurGui: public Ui_PokerServeurGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKERSERVEURGUI_H
