#include "ActionDesignerEditor.h"
#include "ActionEditorModes.h"
#include "ActionEditor.h"

#include "Editor/Kismet/Public/BlueprintEditorTabs.h"
#include "Editor/Kismet/Public/SBlueprintEditorToolbar.h"

const FName FActionEditorModes::ActionEditorName("ActionEditorApp");
const FName FActionEditorModes::ScriptingMode("Script");
const FName FActionEditorModes::TimingMode("Timeline");

//const FName FAblAbilityTimelineSummoner::ID("AblAbilityTimeline");

//
//	Timing Editor Mode
FAppActionEditorTimingMode::FAppActionEditorTimingMode(TSharedPtr<FActionEditor> InActionEditor)
	: FApplicationMode(FActionEditorModes::TimingMode, FActionEditorModes::GetLocalizedMode)
	, ActionEditor(InActionEditor)
{
	TabLayout = FTabManager::NewLayout("ActionDesigner_ActionTimingMode_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				// Top toolbar
				FTabManager::NewStack()
				->SetSizeCoefficient(0.2f)
				->SetHideTabWell(true)
				->AddTab(InActionEditor->GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(

				FTabManager::NewStack()
				->SetSizeCoefficient(0.80f)
				->AddTab("Document", ETabState::ClosedTab)
			)
		);

	//ActionEditorTabFactories.RegisterFactory(MakeShareable(new FAblAbilityPropertiesSummoner(InActionEditor)));

	ToolbarExtender = MakeShareable(new FExtender);
	InActionEditor->GetToolbarBuilder()->AddCompileToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddScriptingToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddBlueprintGlobalOptionsToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddDebuggingToolbar(ToolbarExtender);
}

void FAppActionEditorTimingMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FBlueprintEditor> BP = ActionEditor.Pin();
	BP->RegisterToolbarTab(InTabManager.ToSharedRef());
	BP->PushTabFactories(ActionEditorTabFactories);
}

void FAppActionEditorTimingMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();

	if (ActionEditor.IsValid())
	{
		//ActionEditor.Pin()->Reinitialize();
	}
}

//
//	Scripting Editor Mode
FAppActionEditorScriptingMode::FAppActionEditorScriptingMode(TSharedPtr<FActionEditor> InActionEditor)
	: FBlueprintEditorApplicationMode(StaticCastSharedPtr<FBlueprintEditor>(InActionEditor), FActionEditorModes::ScriptingMode, FActionEditorModes::GetLocalizedMode, false, false)
	, ActionEditor(InActionEditor)
{
	TabLayout = FTabManager::NewLayout("ActionDesigner_ActionScriptingMode_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				// Top toolbar
				FTabManager::NewStack()
				->SetSizeCoefficient(0.2f)
				->SetHideTabWell(true)
				->AddTab(InActionEditor->GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					// Left side
					FTabManager::NewSplitter()
					->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.2f)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.5f)
						//->AddTab(FAblAbilityPropertiesSummoner::ID, ETabState::OpenedTab)
						->AddTab(FBlueprintEditorTabs::MyBlueprintID, ETabState::OpenedTab)
						->SetForegroundTab(FBlueprintEditorTabs::MyBlueprintID)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.5f)
						->AddTab(FBlueprintEditorTabs::DetailsID, ETabState::OpenedTab)
					)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.80f)
					->AddTab("Document", ETabState::ClosedTab)
				)

			)
		);

	//ActionEditorTabFactories.RegisterFactory(MakeShareable(new FAblAbilityPropertiesSummoner(InActionEditor)));

	ToolbarExtender = MakeShareable(new FExtender);
	InActionEditor->GetToolbarBuilder()->AddCompileToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddScriptingToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddBlueprintGlobalOptionsToolbar(ToolbarExtender);
	InActionEditor->GetToolbarBuilder()->AddDebuggingToolbar(ToolbarExtender);
}

void FAppActionEditorScriptingMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FBlueprintEditor> BP = ActionEditor.Pin();
	BP->RegisterToolbarTab(InTabManager.ToSharedRef());
	BP->PushTabFactories(CoreTabFactories);
	BP->PushTabFactories(BlueprintEditorTabFactories);
	BP->PushTabFactories(ActionEditorTabFactories);
}

void FAppActionEditorScriptingMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();

	if (ActionEditor.IsValid())
	{
		//ActionEditor.Pin()->Reinitialize();
	}
}
