modded class Rope: Inventory_Base
{
	ref InventoryLocation m_TargetLocation = new InventoryLocation;
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRestrainTarget);
		AddAction(ActionCraftRopeBelt);
		AddAction(ActionRestrainSelf);
        AddAction(ActionCraftKit);
	}
	
	InventoryLocation GetTargetLocation()
	{
		return m_TargetLocation;
	}
	
	void SetTargetLocation(InventoryLocation targetLocation)
	{
		m_TargetLocation.CopyLocationFrom(targetLocation, true);
	}
	
	override bool CanAssignToQuickbar()
	{
		return (!GetInventory().IsAttachment());
	}
};
