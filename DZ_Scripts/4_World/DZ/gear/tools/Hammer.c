modded class Hammer extends Inventory_Base
{
    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildWoodenPalette);
	}
}