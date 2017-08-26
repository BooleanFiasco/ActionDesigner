// Copyright 2017 Norm Nazaroff.

#include "ActionDesignerEditor.h"

#include "ActionBlueprintAssetTypeActions.h"
#include "ActionInstance.h"
#include "ActionBlueprint.h"
#include "ActionBlueprintFactory.h"
#include "ActionEditor.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

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

void FActionBlueprintAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Object : InObjects)
	{
		if (UBlueprint* Blueprint = Cast<UBlueprint>(Object))
		{
			if (Blueprint->SkeletonGeneratedClass && Blueprint->GeneratedClass)
			{
				// Do we really need a 1:1 relationship with Editor to Asset?
				TSharedRef<FActionEditor> Editor(new FActionEditor());
				TArray<UBlueprint*> Blueprints;
				Blueprints.Add(Blueprint);

				Editor->InitActionEditor(Mode, EditWithinLevelEditor, Blueprints, false);
			}
			else
			{
				// Shouldn't get here unless BP was reparented to an invalid class!
				checkNoEntry();
			}
		}
	}

}

UFactory* FActionBlueprintAssetTypeActions::GetFactoryForBlueprintType(UBlueprint* InBlueprint) const
{
	auto Factory = NewObject<UActionBlueprintFactory>();
	Factory->ParentClass = TSubclassOf<UActionInstance>(*InBlueprint->GeneratedClass);
	return Factory;
}

#undef LOCTEXT_NAMESPACE