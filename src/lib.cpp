#include "task.h"
#include "lib.h"

forensictool::ITask* createTask() {
	return (forensictool::ITask*)(new TaskICQ());
}

