#ifndef CARREGAARQUIVO_H
#define CARREGAARQUIVO_H

#include <QObject>

class CarregaArquivo : public QObject
{
    Q_OBJECT
public:
    explicit CarregaArquivo(QObject *parent = nullptr);
    Q_INVOKABLE QString lerArquivo(const QString filepath); //essa funcao e possivel de ser chamada pelo QML

signals:

};

#endif // CARREGAARQUIVO_H
