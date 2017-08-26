#pragma once

#include "Editor/Kismet/Public/BlueprintEditorModes.h"

#define LOCTEXT_NAMESPACE "ActionEditorModes"

// This is the list of IDs for Action Editor modes
struct FActionEditorModes
{
	// App Name
	static const FName ActionEditorName;

	// Mode constants
	static const FName ScriptingMode;
	static const FName TimingMode;
	static FText GetLocalizedMode(const FName InMode)
	{
		static TMap< FName, FText > LocModes;

		if (LocModes.Num() == 0)
		{
			LocModes.Add(ScriptingMode, NSLOCTEXT("ActionEditorModes", "ScriptingMode", "Script"));
			LocModes.Add(TimingMode, NSLOCTEXT("ActionEditorModes", "TimingMode", "Timeline"));
		}

		check(InMode != NAME_None);
		const FText* OutDesc = LocModes.Find(InMode);
		check(OutDesc);
		return *OutDesc;
	}
private:
	FActionEditorModes() {}
};

class FAppActionEditorTimingMode : public FApplicationMode
{
public:
	FAppActionEditorTimingMode(TSharedPtr<class FActionEditor> ActionEditor);
	//~FAppActionEditorTimingMode();

	// FApplicationMode interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;
	// End of FApplicationMode interface

protected:
	TWeakPtr<class FActionEditor> ActionEditor;
	FWorkflowAllowedTabSet ActionEditorTabFactories;
};

class FAppActionEditorScriptingMode : public FBlueprintEditorApplicationMode
{
public:
	FAppActionEditorScriptingMode(TSharedPtr<class FActionEditor> ActionEditor);
	//~FAppActionEditorScriptingMode();

	// FApplicationMode interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;
	// End of FApplicationMode interface
private:
	TWeakPtr<class FActionEditor> ActionEditor;
	FWorkflowAllowedTabSet ActionEditorTabFactories;
};

#undef LOCTEXT_NAMESPACE
