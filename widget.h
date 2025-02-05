#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_boutonOuvrir_clicked();

    void on_boutonFermer_clicked();

    void on_boutonEnvoyer_clicked();

    void effacer();

    void actualiserMessages();

    void on_boutonRecevoir_clicked();

    void on_boutonEffacer_clicked();

    void on_comboPort_activated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QSerialPort tchat;
    QSerialPort::DataBits num_bits_data;
    QSerialPort::Parity parite;
    QSerialPort::StopBits num_bit_stop;
    QSerialPort::FlowControl flow;
    QSerialPort::Direction direction;
    QDateTime date;
    QString formattedTime;
    QString port = "COM1";
    QString texte_envoi;
    QString texte_affiche;
    QString m_portComTexte;
    QString finalPseudo = "Inconnu";



};
#endif // WIDGET_H
