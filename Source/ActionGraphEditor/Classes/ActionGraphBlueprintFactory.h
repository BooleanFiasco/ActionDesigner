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
	GENERATED_BODY()

public:
	// The type of blueprint that will be created
	UPROPERTY(EditAnywhere, Category = ActionBlueprintFactory)
	TEnumAsByte<EBlueprintType> BlueprintType;

	// The parent class of the created blueprint
	UPROPERTY(EditAnywhere, Category = ActionBlueprintFactory, Meta = (AllowAbstract = ""))
	TSubclassOf<class UActionGraphInstance> ParentClass;

	UActionGraphBlueprintFactory();

	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface
};
