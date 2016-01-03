#include "pokerservergui.h"
#include "ui_pokerservergui.h"
#include <QMessageBox>

class Controller;

PokerServerGui::PokerServerGui(ServerController* servController, QWidget *parent) :
    QMainWindow(parent),
    m_servController(servController),
    m_ui(new Ui::PokerServerGui)
{
    m_ui->setupUi(this);
    m_servController->attachView(this);

    //Connexion des boutons aux slots
    connect(m_ui->actionQuitter, &QAction::triggered, this, &PokerServerGui::slotQuitter);
    connect(m_ui->buttonSend, SIGNAL(clicked()), this, SLOT(slotExecuter()));
}

void PokerServerGui::log(QString log)
{
    m_ui->logs->insertPlainText(log);
    QTextCursor cursor =  m_ui->logs->textCursor();
    cursor.movePosition(QTextCursor::End);
    m_ui->logs->setTextCursor(cursor);
}

PokerServerGui::~PokerServerGui()
{
    delete m_ui;
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
    if(m_ui->commandLine->text() == "") {
        QMessageBox::warning(this, "Champ vide !", "Le champ de commande est vide !");
    } else {
        this->log("# " + m_ui->commandLine->text() + "\n");
        m_ui->commandLine->setText("");
    }
}
