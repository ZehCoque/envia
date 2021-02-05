#include "CarregaArquivo.h"
#include <QDebug>
#include <QFile>

CarregaArquivo::CarregaArquivo(QObject *parent) : QObject(parent)
{

}

QString CarregaArquivo::lerArquivo(QString filepath)
{
    QFile file(filepath.replace(0,7,""));
    QString string; //iniciando a variável que guardará o conteúdo do arquivo

    if (!file.exists()) {
        return "Ocorreu um erro ao ler o arquivo! \nDescrição do erro:\n" + file.errorString();
    }

    if (file.open(QIODevice::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while (!in.atEnd()) {
            string += in.readLine();
        }
    }

    file.close();
    return string;

}
