/********************************************************************************
** Form generated from reading UI file 'pokerservergui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKERSERVERGUI_H
#define UI_POKERSERVERGUI_H

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

class Ui_PokerServerGui
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
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
        PokerServerGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PokerServerGui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 401, 25));
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
