// Copyright 2017 Isaac Hsu.

#pragma once

#include "Factories/Factory.h"
#include "ActionBlueprintFactory.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONDESIGNEREDITOR_API UActionBlueprintFactory : public UFactory
{
	GENERATED_BODY()

public:
	// The type of blueprint that will be created
	UPROPERTY(EditAnywhere, Category = ActionBlueprintFactory)
	TEnumAsByte<EBlueprintType> BlueprintType;

	// The parent class of the created blueprint
	UPROPERTY(EditAnywhere, Category = ActionBlueprintFactory, Meta = (AllowAbstract = ""))
	TSubclassOf<class UActionInstance> ParentClass;

	UActionBlueprintFactory();

	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface
};
