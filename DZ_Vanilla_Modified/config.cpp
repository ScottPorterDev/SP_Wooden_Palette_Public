class CfgPatches
{
	class SP_DZ_Vanilla_Modified_CfgPatches
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables",
			"DZ_Gear_Containers",
			"DZ_Gear_Cooking",
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class WoodenPlank: Inventory_Base
	{
		inventorySlot[]+=
		{
			"SP_Wooden_Planks"
		};
	};
	class Nail: Inventory_Base
	{
		inventorySlot[]+=
		{
			"SP_Nails"
		};
	};
	class Container_Base;
	class Barrel_ColorBase: Container_Base
	{
		inventorySlot[]+=
		{
			"SP_Slot_Barrel_1",
			"SP_Slot_Barrel_2",
			"SP_Slot_Barrel_3",
			"SP_Slot_Barrel_4"
		};
	};
	class FireplaceBase;
	class BarrelHoles_ColorBase: FireplaceBase
	{
		inventorySlot[]+=
		{
			"SP_Slot_Barrel_1",
			"SP_Slot_Barrel_2",
			"SP_Slot_Barrel_3",
			"SP_Slot_Barrel_4"
		};
	};
};
