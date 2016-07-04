#ifndef __WRITER_MESSAGES_H__
#define __WRITER_MESSAGES_H__

#include "task.h"

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDateTime>

class writerMessagesICQ : TaskICQ
{
	public:
		writerMessagesICQ(QString fileName);
		~writerMessagesICQ();

		bool opened();

		void writeAccountInfo_field(QString field_name, QString field_value);
		void writeContactList(QString email,QString name);

	private:
		QFile *m_pFile;
		QXmlStreamWriter* m_pXmlWriter;
		bool m_bOpened;
};

#endif // __WRITER_MESSAGES_H__
