#include "task.h"
#include "writerMessages.h"
#include "XMLReader_ICQContacts.h"

#include <QString>
#include <QRegExp>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QTextStream>
#include <QDebug>
#include <QDirIterator>

TaskICQ::TaskICQ() {
	m_pbDebug = false;
}

//----------------------------------------------------------------------

QString TaskICQ::help()
{
    return "\t--debug - viewing debug messages";
}

//----------------------------------------------------------------------

QString TaskICQ::name()
{
    return "ICQ";
}

//----------------------------------------------------------------------

QStringList TaskICQ::authors()
{
	QStringList listAuthors;
	listAuthors << "Marina Meyta <somekindofcookiemonster@gmail.com>";
	listAuthors << "Yuriy Tereshchenko";
	return listAuthors;
}

//----------------------------------------------------------------------

QString TaskICQ::description()
{
    return "ICQ task for parsing XML-files with ICQ contacts";
}

//----------------------------------------------------------------------

QString TaskICQ::license()
{
	return "MIT License";
}

//----------------------------------------------------------------------

QString TaskICQ::licenseFull()
{
	return "http://forensictool.su/#LICENSE";
}

//----------------------------------------------------------------------

bool TaskICQ::isSupportOS(const forensictool::ITypeOperationSystem *os)
{
    return (os->platform() == "Windows");
}

//----------------------------------------------------------------------

bool TaskICQ::init(const forensictool::IConfig *pConfig)
{
    m_pConfig = pConfig;
    m_pbDebug = m_pConfig->isDebugEnabled();
    return true;
}

//----------------------------------------------------------------------

bool TaskICQ::execute()
{
    if(m_pbDebug)
    {
        qDebug() << "DEBUG MOD";
        qDebug() << QString("Input folder %1").arg(m_pConfig->inputFolder());
        qDebug() << QString("Output folder %1").arg(m_pConfig->outputFolder());
    };

    QString dirStr(m_pConfig->inputFolder());
    QString outDirStr(m_pConfig->outputFolder());
    QDirIterator fileListDirit(dirStr, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    while(fileListDirit.hasNext())
    {
        QString str = QString("%1").arg(fileListDirit.next());
        QFileInfo fInfo(str);
        if(fInfo.suffix() == "xml")
        {
			
            // qDebug() << QString("fInfo.absoluteFilePath() = ").arg(fInfo.absoluteFilePath());
            // парсинг XML-файла с контактами
            XMLReader_ICQContacts reader; // создаем экземпляр класса
            reader.read(fInfo.absoluteFilePath(), outDirStr);
        }
    }

    return true;
}
