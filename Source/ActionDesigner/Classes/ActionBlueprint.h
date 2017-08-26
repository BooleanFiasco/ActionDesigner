#pragma once

#include "ActionDesigner.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Misc/Guid.h"
#include "Engine/Blueprint.h"
#include "ActionBlueprint.generated.h"

UCLASS(BlueprintType)
class ACTIONDESIGNER_API UActionBlueprint : public UBlueprint
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
	// UBlueprint interface
	virtual UClass* GetBlueprintClass() const override;
	virtual bool SupportedByDefaultBlueprintFactory() const override { return false; }
	// End of UBlueprint interface
#endif
};
