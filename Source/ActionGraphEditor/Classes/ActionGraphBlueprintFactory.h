// Copyright 2017 Isaac Hsu.

#pragma once

#include "Factories/Factory.h"
#include "ActionGraphBlueprintFactory.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGRAPHEDITOR_API UActionGraphBlueprintFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface	
};
