// Copyright 2017 Isaac Hsu.

#include "IActionGraphEditor.h"
#include "ActionBlueprintFactory.h"
#include "ActionBlueprint.h"
#include "ActionInstance.h"

UActionBlueprintFactory::UActionBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UActionInstance::StaticClass();
}

UObject* UActionBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UActionBlueprint* NewAsset = NewObject<UActionBlueprint>(InParent, Class, Name, Flags);
	//NewAsset->Sequences.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.Last().EventsToMatch.AddDefaulted();
	// TODO: auto-expand and select first input event
	return NewAsset;
}

