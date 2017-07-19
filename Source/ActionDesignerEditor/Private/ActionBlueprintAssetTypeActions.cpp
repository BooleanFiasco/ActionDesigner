// Copyright 2017 Isaac Hsu.

#include "ActionDesignerEditor.h"

#include "ActionBlueprintAssetTypeActions.h"
#include "ActionInstance.h"
#include "ActionBlueprint.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

//////////////////////////////////////////////////////////////////////////
// FInputCommandAssetTypeActions

FActionBlueprintAssetTypeActions::FActionBlueprintAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FText FActionBlueprintAssetTypeActions::GetName() const
{
	return LOCTEXT("FActionBlueprintAssetTypeActionsName", "Action");
}

FColor FActionBlueprintAssetTypeActions::GetTypeColor() const
{
	return FColor(196, 129, 115);
}

UClass* FActionBlueprintAssetTypeActions::GetSupportedClass() const
{
	return UActionBlueprint::StaticClass();
}

uint32 FActionBlueprintAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE