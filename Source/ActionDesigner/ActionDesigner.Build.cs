// Copyright 2017 Norm Nazaroff.

namespace UnrealBuildTool.Rules
{
	public class ActionDesigner : ModuleRules
	{
		public ActionDesigner(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[]
				{
					"ActionDesigner/Public",
                }
			);

			PrivateIncludePaths.AddRange(
				new string[]
				{
					"ActionDesigner/Private",
					"SlateCore/Public",
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"InputCore",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"CoreUObject",
					"Engine",
					"SlateCore",
                }
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
				}
			);
		}
	}
}
