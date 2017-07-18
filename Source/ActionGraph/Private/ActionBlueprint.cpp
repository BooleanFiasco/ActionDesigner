#include "IActionGraph.h"
#include "ActionBlueprint.h"
#include "ActionBlueprintGeneratedClass.h"

UActionBlueprint::UActionBlueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

#if WITH_EDITOR
UClass* UActionBlueprint::GetBlueprintClass() const
{
	return UActionBlueprintGeneratedClass::StaticClass();
}
#endif