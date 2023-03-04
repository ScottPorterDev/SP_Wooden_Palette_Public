class CfgPatches
{
	class SP_SFX_CfgPatches
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgSoundShaders
{
	class SFX_Succes_SoundShaders
	{
		samples[]=
		{
			
			{
				"\SP_Wooden_Palette\DZ_SFX\Succes.ogg",
				1
			}
		};
		volume=0.5;
	};
};
class CfgSoundSets
{
	class SFX_Succes_SoundSet
	{
		soundShaders[]=
		{
			"SFX_Succes_SoundShaders"
		};
		volumeFactor=0.5;
		frequencyFactor=1;
		startDelay=0;
		doppler=0;
		spatial=0;
	};
};
