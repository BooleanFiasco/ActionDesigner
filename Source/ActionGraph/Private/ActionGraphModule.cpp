// Copyright 2017 Norm Nazaroff.

#include "IActionGraph.h"
#include "Modules/ModuleManager.h"
#include "Engine.h"

class FActionGraphModule : public IActionGraphModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FActionGraphModule, ActionGraph)
DEFINE_LOG_CATEGORY(ActionGraphLog)
#define LOCTEXT_NAMESPACE "ActionGraph"

void FActionGraphModule::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	UE_LOG(ActionGraphLog, Log, TEXT("Action graph module loaded."));
}


void FActionGraphModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(ActionGraphLog, Log, TEXT("Action graph module unloaded."));
}

#undef LOCTEXT_NAMESPACE
