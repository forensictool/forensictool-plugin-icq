#include <iostream>
#include "task.h"
#include "forensictool.h"
#include "forensictool-core/v0.3.1/helpers/config.h"
#include "forensictool-core/v0.3.1/helpers/typeos.h"

void printHelp(QStringList &args){
	forensictool::ITask* pTask = (forensictool::ITask*)(new TaskICQ());
	std::cout << "\n" << pTask->description().toStdString() << "\n\n";
	std::cout << "  Usage: " << args[0].toStdString() << " [OPTIONS] \n\n";
	std::cout << "  OPTIONS:\n\n";
	std::cout << "    -i <fullpath>      - Input folder, required parameter\n";
	std::cout << "    -o <fullpath>      - Output folder, required parameter\n";
	std::cout << "    -h/--help          - this help\n";
	std::cout << "\n";
	std::cout << "  Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_BUILD << "\n";
	std::cout << "  Author: " << pTask->authors().join(", ").toStdString() << "\n";
	std::cout << "  License: " << pTask->license().toStdString() << "\n";
	std::cout << "\n";
}

int main(int argc, char* argv[])
{
	QStringList args;
	for(int i = 0; i < argc; i++){
		args << QString(argv[i]);
	}
	
	if(!args.contains("-i") || !args.contains("-o")){
		printHelp(args);
		return -1;
	}

	if(args.contains("--help")){
		printHelp(args);
		return 0;
	}
	
	QString inputFolder = "";
	if(args.contains("-i") && args.indexOf("-i") + 1 > args.size()){
		std::cout << "\nERROR: Could not found parameter for '-i'\n";
		printHelp(args);
		return -2;
	}else{
		inputFolder = args[args.indexOf("-i") + 1];
	}
	
	QString outputFolder = "";
	if(args.contains("-o") && args.indexOf("-o") + 1 > args.size()){
		std::cout << "\nERROR: Could not found parameter for '-o'\n";
		printHelp(args);
		return -3;
	}else{
		outputFolder = args[args.indexOf("-o") + 1];
	}
	
	args << "--debug"; // always debug on
	
	forensictool::IConfig *pConfig = (forensictool::IConfig *)(new Config());
	
	pConfig->setParameters(args);
	pConfig->setInputFolder(inputFolder);
	pConfig->setOutputFolder(outputFolder);
	pConfig->setTypeOS((forensictool::ITypeOperationSystem *)(new TypeOS()));

	forensictool::ITask* pTask = (forensictool::ITask*)(new TaskICQ());
	std::cout << "\n\n";
	pTask->init(pConfig);
	pTask->execute();
	return 0;
};
