class CfgPatches
{
	class SP_DZ_Slots_Modded_CfgPatches
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
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySP_Proxy_Nails: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Nails";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_Nails.p3d";
	};
	class ProxySP_Proxy_WoodenPlanks: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Wooden_Planks";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_WoodenPlanks.p3d";
	};
	class ProxySP_Proxy_Barrel_1: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Slot_Barrel_1";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_Barrel_1.p3d";
	};
	class ProxySP_Proxy_Barrel_2: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Slot_Barrel_2";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_Barrel_2.p3d";
	};
	class ProxySP_Proxy_Barrel_3: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Slot_Barrel_3";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_Barrel_3.p3d";
	};
	class ProxySP_Proxy_Barrel_4: ProxyAttachment
	{
		scope=2;
		inventorySlot="SP_Slot_Barrel_4";
		model="\SP_Wooden_Palette\DZ_Slots_Modded\DZ_Proxys\SP_Proxy_Barrel_4.p3d";
	};
};
class CfgSlots
{
	class Slot_SP_Wooden_Planks
	{
		name="SP_Wooden_Planks";
		displayName="#STR_CfgPlanks0";
		selection="SP_Wooden_Planks";
		ghostIcon="set:dayz_inventory image:planks";
		stackMax=10;
	};
	class Slot_SP_Nails
	{
		name="SP_Nails";
		displayName="#STR_CfgNails0";
		selection="SP_Nails";
		ghostIcon="set:dayz_inventory image:nails";
		stackMax=40;
	};
	class Slot_SP_Slot_Barrel_1
	{
		name="SP_Slot_Barrel_1";
		displayName="#STR_CfgBarrel0";
		ghostIcon="set:dayz_inventory image:barrel";
		selection="SP_Slot_Barrel_1";
	};
	class Slot_SP_Slot_Barrel_2
	{
		name="SP_Slot_Barrel_2";
		displayName="#STR_CfgBarrel0";
		ghostIcon="set:dayz_inventory image:barrel";
		selection="SP_Slot_Barrel_2";
	};
	class Slot_SP_Slot_Barrel_3
	{
		name="SP_Slot_Barrel_3";
		displayName="#STR_CfgBarrel0";
		ghostIcon="set:dayz_inventory image:barrel";
		selection="SP_Slot_Barrel_3";
	};
	class Slot_SP_Slot_Barrel_4
	{
		name="SP_Slot_Barrel_4";
		displayName="#STR_CfgBarrel0";
		ghostIcon="set:dayz_inventory image:barrel";
		selection="SP_Slot_Barrel_4";
	};
};
