// Copyright 2017 Isaac Hsu.

#include "IActionGraphEditor.h"
#include "ActionGraphBlueprintFactory.h"
#include "ActionGraphBlueprint.h"
#include "ActionGraphInstance.h"

UActionGraphBlueprintFactory::UActionGraphBlueprintFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UActionGraphInstance::StaticClass();
}

UObject* UActionGraphBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UActionGraphBlueprint* NewAsset = NewObject<UActionGraphBlueprint>(InParent, Class, Name, Flags);
	//NewAsset->Sequences.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.Last().EventsToMatch.AddDefaulted();
	// TODO: auto-expand and select first input event
	return NewAsset;
}

