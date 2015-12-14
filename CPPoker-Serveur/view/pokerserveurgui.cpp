#include "pokerserveurgui.h"
#include "ui_pokerserveurgui.h"
#include <QMessageBox>

PokerServeurGui::PokerServeurGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokerServeurGui)
{
    ui->setupUi(this);

    //Taille de la fenêtre non modifiable
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //Connexion des boutons aux slots
    connect(ui->actionQuitter, &QAction::triggered, this, &PokerServeurGui::slotQuitter);
    connect(ui->buttonSend, SIGNAL(clicked()), this, SLOT(slotExecuter()));
}

PokerServeurGui::~PokerServeurGui()
{
    delete ui;
}

void PokerServeurGui::slotQuitter()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quitter ?", "Voulez-vous vraiment arrêter le serveur ?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QCoreApplication::quit();
    }
}

void PokerServeurGui::slotExecuter()
{    
    if(ui->commandLine->text() == ""){
        QMessageBox::warning(this, "Champ vide !", "Le champ de commande est vide !");
    }else{
        ui->logs->insertPlainText("# " + ui->commandLine->text() + "\n");
        ui->commandLine->setText("");
        QTextCursor cursor =  ui->logs->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->logs->setTextCursor(cursor);
    }
}
