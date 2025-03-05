/*
 * Tchat liason série
 * Auteur : Elias GAUTHIER
 * Promo : BTS CIEL2
 * Date : 13.11.2024
*/

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(340,309);
    ui->boutonFermer->setDisabled(true);
    ui->boutonEnvoyer->setDisabled(true);
    ui->lineEdit->setDisabled(true);
    ui->labelInfo->setText("");


    // Configuration port, vitesse
    num_bits_data=QSerialPort::Data8;
    tchat.setPortName(port);
    direction=QSerialPort::AllDirections;
    qint32 vitesse = 9600;
    tchat.setDataBits(num_bits_data);
    tchat.setBaudRate(vitesse,direction);

    // Parité
    parite  = QSerialPort::EvenParity;
    tchat.setParity(parite);

    // Bit de stop
    num_bit_stop = QSerialPort::OneStop;
    tchat.setStopBits(num_bit_stop);

    // Flow control
    flow = QSerialPort::NoFlowControl;
    tchat.setFlowControl(flow);

    // DTR
    bool dtr=false;
    tchat.setDataTerminalReady(dtr);
    connect(&tchat, SIGNAL(readyRead()), this, SLOT(actualiserMessages()));
    QList<QSerialPortInfo> listePort = QSerialPortInfo::availablePorts();

    for (int i=0;i<listePort.size();i++)
    {
        QString listePortTexte =
            listePort[i].portName()
            +" - "
            +listePort[i].description()
            +" ("
            +listePort[i].manufacturer()
            +")";
        ui->comboPort->addItem(listePortTexte);
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_boutonOuvrir_clicked()
{
    date = QDateTime::currentDateTime();
    formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    ui->TextEditZoneMessages->append(formattedTime+" Ouverture de la communication.");
    if (tchat.open(QIODevice::ReadWrite)){
        ui->labelInfo->setText("Port ouvert");
        ui->TextEditZoneMessages->append("En attente de réception...");
        ui->lineEdit->setDisabled(false);
        ui->boutonEnvoyer->setDisabled(false);
        ui->boutonOuvrir->setDisabled(true);
        ui->boutonFermer->setDisabled(false);

        // RTS
        bool rts=false;
        tchat.setRequestToSend(rts);

    }
    else {
        ui->TextEditZoneMessages->append(formattedTime+" Impossible d'ouvrir le port "+port);
    }
}

void Widget::on_boutonFermer_clicked()
{
    date = QDateTime::currentDateTime();
    formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    tchat.close();
    ui->labelInfo->setText("Port fermé");
    ui->lineEdit->setDisabled(true);
    ui->boutonEnvoyer->setDisabled(true);
    formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    ui->boutonOuvrir->setDisabled(false);
    ui->boutonFermer->setDisabled(true);
    ui->TextEditZoneMessages->append(formattedTime+" Fermeture de la communication.");
}

void Widget::on_boutonEnvoyer_clicked()
{
    if (ui->lineEdit->text()=="/help"){
        ui->TextEditZoneMessages->setText("Liste des commandes :\r\n/clear : Effacer la zone de messagerie\r\n/test : Envoyer un message de test\r\n/pseudo <pseudo> : Changer de pseudo");
        ui->lineEdit->clear();
    }
    else if (ui->lineEdit->text().contains("/pseudo")){
        date = QDateTime::currentDateTime();
        formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
        QString commandePseudo = ui->lineEdit->text();
        QStringList pseudo = commandePseudo.split(" ");
        finalPseudo = pseudo.last();
        ui->TextEditZoneMessages->append(formattedTime+" Pseudo modifié par "+finalPseudo);
        ui->lineEdit->clear();

    }
    else if (ui->lineEdit->text()=="/clear"){
        ui->TextEditZoneMessages->clear();
        date = QDateTime::currentDateTime();
        formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
        ui->TextEditZoneMessages->append(formattedTime+" Zone de messages nettoyée");
        ui->labelInfo->setText("Zone de messages nettoyée");
        ui->lineEdit->clear();
    }
    else{
        ui->labelInfo->setText("Envoi en cours...");

        if (ui->lineEdit->text()=="/test"){
            texte_envoi="Ceci est un message de test";
        }
        else{
            texte_envoi=ui->lineEdit->text()+"\r\n";
        }
        if (texte_envoi!=""){
            QString dtext = finalPseudo+": "+texte_envoi;
            QByteArray ftext= dtext.toLatin1();
            tchat.write(ftext);
            ui->labelInfo->setText("Message envoyé");
            ui->TextEditZoneMessages->append(finalPseudo+": "+texte_envoi);
            ui->lineEdit->clear();
        }
    }
}


void Widget::actualiserMessages()
{
    ui->labelInfo->setText("Actualisation..");

    QByteArray texte_recu_qba=tchat.readAll();
    QString texte_recu = QString::fromLatin1(texte_recu_qba);
    if(texte_recu!=""){
        ui->TextEditZoneMessages->append(texte_recu);
        ui->labelInfo->setText("Message reçu");
    }
}


void Widget::on_comboPort_activated(const QString &arg1)
{
    m_portComTexte = arg1.section(' ',0,0);
    tchat.setPortName(port);
}

