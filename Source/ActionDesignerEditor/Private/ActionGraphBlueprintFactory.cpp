// Copyright 2017 Isaac Hsu.

#include "ActionDesignerEditor.h"
#include "ActionGraphBlueprintFactory.h"
#include "ActionGraphBlueprint.h"
#include "ActionGraphBlueprintGeneratedClass.h"
#include "ActionGraphInstance.h"

// CreateBlueprint()
#include "Kismet2/KismetEditorUtilities.h"

// Parent class picker dialog
#include "ClassViewerModule.h"
#include "ClassViewerFilter.h"

UActionGraphBlueprintFactory::UActionGraphBlueprintFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UActionGraphBlueprint::StaticClass();
	BlueprintType = EBlueprintType::BPTYPE_Normal;
	ParentClass = UActionGraphInstance::StaticClass();
}

UObject* UActionGraphBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	auto NewAsset = CastChecked<UActionGraphBlueprint>(FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BlueprintType, UActionGraphBlueprint::StaticClass(), UActionGraphBlueprintGeneratedClass::StaticClass(), CallingContext));
	//UActionBlueprint* NewAsset = NewObject<UActionBlueprint>(InParent, Class, Name, Flags);
	//NewAsset->Sequences.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.AddDefaulted();
	//NewAsset->Sequences.Last().Entries.Last().EventsToMatch.AddDefaulted();
	// TODO: auto-expand and select first input event
	return NewAsset;
}

UObject* UActionGraphBlueprintFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return FactoryCreateNew(Class, InParent, Name, Flags, Context, Warn, NAME_None);
}

