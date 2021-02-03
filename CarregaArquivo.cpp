#include "CarregaArquivo.h"
#include <QDebug>
#include <QFile>

CarregaArquivo::CarregaArquivo(QObject *parent) : QObject(parent)
{

}

QString CarregaArquivo::lerArquivo(QString filepath)
{
    qDebug() << filepath;
    QFile file(filepath.replace(0,8,""));
    QString strings;

    if (!file.exists()) {
        return "Ocorreu um erro ao ler o arquivo! \nDescrição do erro:\n" + file.errorString();
    }

    if (file.open(QIODevice::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while (!in.atEnd()) {
            strings += in.readLine();
            qDebug() << strings;
        }
    }

    file.close();
    return strings;

}
