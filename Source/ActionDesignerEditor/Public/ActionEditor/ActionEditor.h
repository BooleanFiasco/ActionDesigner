#pragma once

#include "Editor/Kismet/Public/BlueprintEditor.h"

#include "ActionEditorToolbar.h"
#include "ActionEditorCommands.h"
#include "ActionEditorViewportClient.h"

struct FSlateBrush;

/* Able Ability Editor, extends Blueprint Editor. */
class FActionEditor : public FBlueprintEditor
{
public:
	/* Initializes an instance of the Editor. */
	void InitActionEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, const TArray<UBlueprint*>& InAbilityBlueprints, bool ShouldUseDataOnlyEditor);

	FActionEditor();
	~FActionEditor();

	// IToolkit interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	// End of IToolkit interface

	virtual UBlueprint* GetBlueprintObj() const override;

	//~ Begin FTickableEditorObject Interface
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	//~ End FTickableEditorObject Interface

protected:
	virtual void GetSaveableObjects(TArray<UObject*>& OutObjects) const override;

	void ExtendMenu();
	void ExtendToolbar();
	void BindCommands();

	const FSlateBrush* TabIcon;

	// Extenders
	TSharedPtr<FExtender> ToolbarExtender;
	TSharedPtr<FExtender> MenuExtender;

	// Editor Toolbar
	TSharedPtr<FActionEditorToolbar> ActionEditorToolbar;
};
