class CfgPatches
{
	class SP_Wooden_Palette_CfgPatches
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Camping"
		};
	};
};
class CfgMods
{
	class SP_Wooden_Palette_CfgMods
	{
		dir="SP_Wooden_Palette";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="SP_Wooden_Palette";
		author="Scott Porter";
		authorID="0";
		version="1.5";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SP_Wooden_Palette\DZ_Scripts\4_World"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SP_Wooden_Palette: Inventory_Base
	{
		displayname="Wooden Pallet";
		descriptionShort="A wooden pallet that can support heavy loads.";
		scope=2;
		model="\SP_Wooden_Palette\Wooden_Palette\model\SP_Wooden_Pallet.p3d";
		physLayer="ItemLarge";
		alignHologramToTerain=1;
		soundImpactType="wood";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"SP_Wooden_Palette\Wooden_Palette\data\SP_Palette_BC.paa"
		};
		attachments[]=
		{
			"SP_Slot_Barrel_1",
			"SP_Slot_Barrel_2",
			"SP_Slot_Barrel_3",
			"SP_Slot_Barrel_4"
		};
		attachmentSlots[]=
		{
			"SP_Slot_Barrel_1",
			"SP_Slot_Barrel_2",
			"SP_Slot_Barrel_3",
			"SP_Slot_Barrel_4"
		};
	};
	class SP_Wooden_Palette_Kit: Inventory_Base
	{
		scope=2;
		displayName="Wooden Pallet Kit";
		descriptionShort="This kit facilitates the construction of a wooden pallet.";
		model="\DZ\gear\camping\watchtower_kit.p3d";
		rotationFlags=17;
		itemSize[]={1,5};
		weight=280;
		itemBehaviour=1;
		attachments[]=
		{
			"Rope"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage=10;
						};
						class Blood
						{
							damage=0;
						};
						class Shock
						{
							damage=0;
						};
					};
					class FragGrenade
					{
						class Health
						{
							damage=0;
						};
						class Blood
						{
							damage=0;
						};
						class Shock
						{
							damage=0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class AnimSourceHidden
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Inventory: AnimSourceHidden
			{
			};
			class Placing: AnimSourceHidden
			{
			};
		};
		soundImpactType="wood";
	};
	class SP_Wooden_Palette_Kit_Deployed: SP_Wooden_Palette
	{
		displayName="Wooden Pallet Kit";
		descriptionShort="This kit facilitates the construction of a wooden pallet.";
		scope=2;
		storageCategory=10;
		alignHologramToTerain=1;
		hiddenSelectionsTextures[]=
		{
			"\SP_Wooden_Palette\Wooden_Palette\data\SP_Palette_Holo.paa"
		};
		attachments[]=
		{
			"SP_Wooden_Planks",
			"SP_Nails"
		};
		class GUIInventoryAttachmentsProps
		{
			class Rangement_Slot
			{
				name="Ressources Building";
				description="";
				attachmentSlots[]=
				{
					"SP_Wooden_Planks",
					"SP_Nails"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
			};
		};
	};
};
