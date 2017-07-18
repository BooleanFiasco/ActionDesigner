// Copyright 2017 Isaac Hsu.

#include "IActionGraphEditor.h"
#include "ActionBlueprintFactory.h"
#include "ActionBlueprint.h"
#include "ActionBlueprintGeneratedClass.h"
#include "ActionInstance.h"

// CreateBlueprint()
#include "Kismet2/KismetEditorUtilities.h"

// Parent class picker dialog
#include "ClassViewerModule.h"
#include "ClassViewerFilter.h"

UActionBlueprintFactory::UActionBlueprintFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UActionBlueprint::StaticClass();
	BlueprintType = EBlueprintType::BPTYPE_Normal;
	ParentClass = UActionInstance::StaticClass();
}

UObject* UActionBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	auto NewAsset = CastChecked<UActionBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BlueprintType, UActionBlueprint::StaticClass(), UActionBlueprintGeneratedClass::StaticClass(), CallingContext));
	//UActionBlueprint* NewAsset = NewObject<UActionBlueprint>(InParent, Class, Name, Flags);
	//NewAsset->Sequences.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.Last().EventsToMatch.AddDefaulted();
	// TODO: auto-expand and select first input event
	return NewAsset;
}

UObject* UActionBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}
