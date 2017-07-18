// Copyright 2017 Norm Nazaroff.

#include "IActionGraphEditor.h"
#include "AutomationTest.h"
#include "AutomationEditorCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FActionGraphTest, "Plugins.ActionGraph.ActionGraph", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FActionGraphTest::RunTest(const FString& Parameters)
{
	UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
	World->Tick(LEVELTICK_All, 1.f);

	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS