#include "ActionDesignerEditor.h"
#include "ActionEditor.h"

#include "ActionEditorModes.h"
#include "ActionEditorCommands.h"

#include "ActionBlueprint.h"

#include "Editor.h"
#include "EditorStyleSet.h"
#include "EditorReimportHandler.h"
#include "Editor/Kismet/Public/SBlueprintEditorToolbar.h"
#include "Engine/Blueprint.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Logging/LogMacros.h"
#include "GameFramework/WorldSettings.h"
#include "MultiBox/MultiBoxExtender.h"
#include "ScopedTransaction.h"
#include "SDockTab.h"
#include "TabManager.h"
#include "UObject/Object.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "GraphEditorActions.h"

#define LOCTEXT_NAMESPACE "ActionEditor"

FActionEditor::FActionEditor()
{
	//m_EditorSettings = GetMutableDefault<UAblAbilityEditorSettings>(UAblAbilityEditorSettings::StaticClass());
	//m_Validator = GetMutableDefault<UAblAbilityValidator>(UAblAbilityValidator::StaticClass());

	//check(m_EditorSettings);

	// Slightly annoying/obfuscated setting. This setting can prevent particles from being drawn - not sure why.
	// Persona calls this out but only mentions that it's attached effects but it's all effects.
	//m_PreviewScene.GetWorld()->GetWorldSettings()->SetIsTemporarilyHiddenInEditor(false);
}

FActionEditor::~FActionEditor()
{
	FEditorDelegates::OnAssetPostImport.RemoveAll(this);
	FReimportManager::Instance()->OnPostReimport().RemoveAll(this);
}

void FActionEditor::InitActionEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, const TArray<UBlueprint*>& InAbilityBlueprints, bool ShouldUseDataOnlyEditor)
{
	check(InAbilityBlueprints.Num() > 0);

	/*if (!m_AssetDirtyBrush)
	{
		m_AssetDirtyBrush = FEditorStyle::GetBrush("ContentBrowser.ContentDirty");
	}

	if (!m_TabIcon)
	{
		m_TabIcon = FAbleStyle::GetBrush("Able.Tabs.AbilityTimeline");
	}*/

	//FActionEditorCommands::Register();
	//BindCommands();

	// Init stuff.
	TSharedPtr<FActionEditor> Editor(SharedThis(this));

	if (!Toolbar.IsValid())
	{
		Toolbar = MakeShareable(new FBlueprintEditorToolbar(SharedThis(this)));
	}

	if (!ActionEditorToolbar.IsValid())
	{
		ActionEditorToolbar = MakeShareable(new FActionEditorToolbar());
	}

	TArray<UObject*> ObjectsBeingEditted;
	for (UBlueprint* BP : InAbilityBlueprints)
	{
		ObjectsBeingEditted.Add(BP);
	}

	// Modes
	TSharedRef<FApplicationMode> ScriptingMode = MakeShareable(new FAppActionEditorScriptingMode(Editor));
	TSharedRef<FApplicationMode> TimingMode = MakeShareable(new FAppActionEditorTimingMode(Editor));

	AddApplicationMode(ScriptingMode->GetModeName(), ScriptingMode);
	AddApplicationMode(TimingMode->GetModeName(), TimingMode);

	// Initialize the asset editor and spawn tabs
	const TSharedRef<FTabManager::FLayout> DummyLayout = FTabManager::NewLayout("NullLayout")->AddArea(FTabManager::NewPrimaryArea());
	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, FActionEditorModes::ActionEditorName, DummyLayout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, ObjectsBeingEditted);

	CommonInitialization(InAbilityBlueprints);

	// Custom Menu/Toolbar
	ExtendMenu();
	ExtendToolbar();

	// Regenerate everything.
	RegenerateMenusAndToolbars();

	// This does the actual layout generation.
	SetCurrentMode(ScriptingMode->GetModeName());

	PostLayoutBlueprintEditorInitialization();

	//FAbleEditorEventManager::Get().BroadcastAbilityEditorInstantiated(*this);
}

FName FActionEditor::GetToolkitFName() const
{
	return FName("ActionEditor");
}

FText FActionEditor::GetBaseToolkitName() const
{
	return LOCTEXT("ActionEditorAppLabel", "Action Editor");
}

FText FActionEditor::GetToolkitName() const
{
	const TArray<UObject *>& CurrentEditingObjects = GetEditingObjects();

	check(CurrentEditingObjects.Num() > 0);

	FFormatNamedArguments Args;

	const UObject* EditingObject = CurrentEditingObjects[0];

	const bool bDirtyState = EditingObject->GetOutermost()->IsDirty();

	Args.Add(TEXT("ObjectName"), FText::FromString(EditingObject->GetName()));
	Args.Add(TEXT("DirtyState"), bDirtyState ? FText::FromString(TEXT("*")) : FText::GetEmpty());
	return FText::Format(LOCTEXT("ActionToolkitName", "{ObjectName}{DirtyState}"), Args);
}

FText FActionEditor::GetToolkitToolTipText() const
{
	const UObject* EditingObject = GetEditingObject();

	check(EditingObject != NULL);

	return FAssetEditorToolkit::GetToolTipTextForObject(EditingObject);
}

FString FActionEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("ActionEditor");
}

FLinearColor FActionEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

UBlueprint* FActionEditor::GetBlueprintObj() const
{
	for (UObject* EditingObject : GetEditingObjects())
	{
		if (EditingObject->IsA<UActionBlueprint>())
		{
			return CastChecked<UBlueprint>(EditingObject);
		}
	}

	return nullptr;
}

void FActionEditor::Tick(float DeltaTime)
{
	FBlueprintEditor::Tick(DeltaTime);

	/*if (m_Viewport.IsValid())
	{
		m_Viewport.Pin()->RefreshViewport();
	}

	if (m_PreviewActor.IsValid())
	{
		if (USkeletalMeshComponent* SkeletalComponent = m_PreviewActor->FindComponentByClass<USkeletalMeshComponent>())
		{
			if (SkeletalComponent->GetAnimationMode() == EAnimationMode::AnimationBlueprint)
			{
				// Manually Update our AnimBlueprint
				if (UAnimInstance* AnimationInstance = SkeletalComponent->GetAnimInstance())
				{
					AnimationInstance->BlueprintUpdateAnimation(DeltaTime);
				}
			}
		}

		if (UMeshComponent* MeshComponent = m_PreviewActor->FindComponentByClass<UMeshComponent>())
		{
			MeshComponent->SetRelativeRotation(GetEditorSettings().m_MeshRotation);
		}
	}

	if (!IsPlayingAbility() && IsPaused())
	{
		// Reset our Pause state.
		m_IsPaused = false;
	}*/
}

TStatId FActionEditor::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FActionEditor, STATGROUP_Tickables);
}

void FActionEditor::GetSaveableObjects(TArray<UObject*>& OutObjects) const
{
	// We're about to save. Go ahead and sort our tasks to maintain order.
	//GetAbility()->SortTasks();

	//OutObjects.Append(GetEditingObjects());
}

void FActionEditor::ExtendMenu()
{
	if (MenuExtender.IsValid())
	{
		RemoveMenuExtender(MenuExtender);
		MenuExtender.Reset();
	}

	MenuExtender = MakeShareable(new FExtender);

	FKismet2Menu::SetupBlueprintEditorMenu(MenuExtender, *this);

	// Custom Menus for Ability Editor
	/*{
		struct Local
		{
			static void AddAbilityFileMenu(FMenuBuilder& MenuBuilder)
			{
				// View
				MenuBuilder.BeginSection("FAblAbilityEditor", LOCTEXT("AbilityEditorMenu_File", "Blueprint"));
				{
				}
				MenuBuilder.EndSection();
			}

			static void AddAbilityTimelineMenu(FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.BeginSection("EditTimeline", LOCTEXT("AbilityEditorMenu_Timeline", "Timeline"));
				{
					MenuBuilder.AddMenuEntry(FAblAbilityEditorCommands::Get().m_ToggleShowCollisionQueries);
					MenuBuilder.AddMenuSeparator();
					MenuBuilder.AddMenuEntry(FAblAbilityEditorCommands::Get().m_ToggleDrawArrowComponent);
					MenuBuilder.AddMenuEntry(FAblAbilityEditorCommands::Get().m_ToggleDrawCharacterCollision);
					MenuBuilder.AddMenuEntry(FAblAbilityEditorCommands::Get().m_ToggleDrawCameraComponent);
				}
				MenuBuilder.EndSection();
			}

			static void AddAbilityTimelineDropdownMenu(FMenuBarBuilder& MenuBarBuilder)
			{
				MenuBarBuilder.AddPullDownMenu(LOCTEXT("Timeline", "Timeline"),
					LOCTEXT("Timeline_Tooltip", "Opens the Timeline Menu"),
					FNewMenuDelegate::CreateStatic(&Local::AddAbilityTimelineMenu),
					"Timeline");
			}
		};


		m_MenuExtender->AddMenuBarExtension(
			"Edit",
			EExtensionHook::After,
			GetToolkitCommands(),
			FMenuBarExtensionDelegate::CreateStatic(&Local::AddAbilityTimelineDropdownMenu));
	}*/

	AddMenuExtender(MenuExtender);
}

void FActionEditor::ExtendToolbar()
{
	// If the ToolbarExtender is valid, remove it before rebuilding it
	if (ToolbarExtender.IsValid())
	{
		RemoveToolbarExtender(ToolbarExtender);
		ToolbarExtender.Reset();
	}

	ToolbarExtender = MakeShareable(new FExtender);
	ActionEditorToolbar->AddActionEditorModesToolbar(ToolbarExtender, SharedThis(this));

	if (GetCurrentMode() == FActionEditorModes::TimingMode)
	{
		//ActionEditorToolbar->AddTimelineToolbar(ToolbarExtender, SharedThis(this));
	}

	AddToolbarExtender(ToolbarExtender);
}

void FActionEditor::BindCommands()
{
	const FActionEditorCommands& Commands = FActionEditorCommands::Get();

	const TSharedRef<FUICommandList>& UICommandList = GetToolkitCommands();

	/*UICommandList->MapAction(Commands.m_AddTask,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::AddNewTask));
	UICommandList->MapAction(Commands.m_RemoveTask,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::RemoveCurrentTask));
	UICommandList->MapAction(Commands.m_PlayAbility,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::PlayAbility));
	UICommandList->MapAction(Commands.m_StopAbility,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::StopAbility),
		FCanExecuteAction::CreateSP(this, &FAblAbilityEditor::IsPlayingAbility));
	UICommandList->MapAction(Commands.m_StepAbility,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::StepAbility),
		FCanExecuteAction::CreateSP(this, &FAblAbilityEditor::IsPaused));
	UICommandList->MapAction(Commands.m_Resize,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ResizeAbility));
	UICommandList->MapAction(Commands.m_Validate,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::Validate));
	UICommandList->MapAction(Commands.m_SetPreviewAsset,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::SetPreviewAsset));
	UICommandList->MapAction(Commands.m_ResetPreviewAsset,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ResetPreviewActor));
	UICommandList->MapAction(Commands.m_ToggleCost,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ToggleCostView),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FAblAbilityEditor::ShowTaskCostEstimate));
	UICommandList->MapAction(Commands.m_ToggleShowCollisionQueries,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ToggleShowQueryVolumes),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FAblAbilityEditor::IsDrawingCollisionQueries));
	UICommandList->MapAction(Commands.m_CaptureThumbnail,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::CaptureThumbnail));
	UICommandList->MapAction(Commands.m_ToggleDrawArrowComponent,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ToggleDrawArrowComponent),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FAblAbilityEditor::IsDrawingArrowComponent));
	UICommandList->MapAction(Commands.m_ToggleDrawCameraComponent,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ToggleDrawCameraComponent),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FAblAbilityEditor::IsDrawingCameraComponent));
	UICommandList->MapAction(Commands.m_ToggleDrawCharacterCollision,
		FExecuteAction::CreateSP(this, &FAblAbilityEditor::ToggleDrawCharacterCollision),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FAblAbilityEditor::IsDrawingCharacterCollision));*/
}

#undef LOCTEXT_NAMESPACE
