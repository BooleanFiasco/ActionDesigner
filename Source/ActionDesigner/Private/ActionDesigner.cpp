// Copyright 2017 Norm Nazaroff.

#include "ActionDesigner.h"
#include "Modules/ModuleManager.h"
#include "Engine.h"

class FActionDesignerModule : public IActionDesignerModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FActionDesignerModule, ActionDesigner)
DEFINE_LOG_CATEGORY(ActionDesignerLog)
#define LOCTEXT_NAMESPACE "ActionDesigner"

void FActionDesignerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	UE_LOG(ActionDesignerLog, Log, TEXT("Action Designer module loaded."));
}


void FActionDesignerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(ActionDesignerLog, Log, TEXT("Action Designer module unloaded."));
}

#undef LOCTEXT_NAMESPACE
