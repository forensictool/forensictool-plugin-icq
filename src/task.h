#ifndef __FORENSICTOOL_TASK_ICQ_H__
#define __FORENSICTOOL_TASK_ICQ_H__

#include "forensictool.h"

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDateTime>


class TaskICQ : public forensictool::ITask
{
    public:
		TaskICQ();
		virtual QString help();
		virtual QString name();
		virtual QStringList authors();
		virtual QString description();
		virtual QString license();
		virtual QString licenseFull();

        virtual bool isSupportOS(const forensictool::ITypeOperationSystem *os);
		virtual bool init(const forensictool::IConfig *pConfig);
		virtual bool execute();

    private:
        bool m_pbDebug;
        const forensictool::IConfig *m_pConfig;
};

extern "C"
{
	forensictool::ITask* createTask();
}

#endif // __FORENSICTOOL_TASK_ICQ_H__
