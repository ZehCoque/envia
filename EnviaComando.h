#ifndef ENVIACOMANDO_H
#define ENVIACOMANDO_H

#include <QObject>

#define SERVICE_NAME            "otmis.Desafio"

class EnviaComando : public QObject
{
    Q_OBJECT

public:
    explicit EnviaComando(QObject *parent = nullptr);
    Q_INVOKABLE void sendCommand(const QString topic, const QString msg); //o QML chama essa funcao quando vai enviar uma mensagem pelo DBus

signals:

};

#endif // ENVIACOMANDO_H
