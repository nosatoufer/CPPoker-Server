#include "pokerservergui.h"
#include "ui_pokerservergui.h"
#include <QMessageBox>

class Controller;

PokerServerGui::PokerServerGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokerServerGui)
{
    ui->setupUi(this);

    //Taille de la fenêtre non modifiable
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //Connexion des boutons aux slots
    connect(ui->actionQuitter, &QAction::triggered, this, &PokerServerGui::slotQuitter);
    connect(ui->buttonSend, SIGNAL(clicked()), this, SLOT(slotExecuter()));
}

PokerServerGui::~PokerServerGui()
{
    delete ui;
}

void PokerServerGui::attachController(Controller* controller)
{
    this->controller = controller;
}

void PokerServerGui::slotQuitter()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quitter ?", "Voulez-vous vraiment arrêter le serveur ?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QCoreApplication::quit();
    }
}

void PokerServerGui::slotExecuter()
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
