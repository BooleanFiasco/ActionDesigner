// Copyright 2017 Norm Nazaroff.

namespace UnrealBuildTool.Rules
{
	public class ActionGraph : ModuleRules
	{
		public ActionGraph(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[]
				{
					"ActionGraph/Public",
                }
			);

			PrivateIncludePaths.AddRange(
				new string[]
				{
					"ActionGraph/Private",
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
