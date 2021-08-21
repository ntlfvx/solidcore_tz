// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tz_Solidcore_v01 : ModuleRules
{
	public Tz_Solidcore_v01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" , "UMG", "Slate", "SlateCore"});
	}
}
