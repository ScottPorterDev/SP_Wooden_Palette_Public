
class SP_Wooden_Palette_Kit_Deployed extends Inventory_Base
{
	//Sounds
	ref protected EffectSound 	m_SFX_Succes_2;
	/*string SFX_Succes_SoundSet() {};*/

	override bool CanPutInCargo( EntityAI parent )
	{
		if ( !super.CanPutInCargo(parent) ) {return false;}
		return false;
	}

	override bool CanPutIntoHands( EntityAI player )
	{
		if ( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		return false;
	}

	bool CheckSlotsAvailables()
	{
		int SP_WoodenPlanks;
		int SP_Nails_Slot;

		SP_WoodenPlanks = InventorySlots.GetSlotIdFromString("SP_Wooden_Planks");
		SP_Nails_Slot = InventorySlots.GetSlotIdFromString("SP_Nails");

		ItemBase SP_WoodenPlanks_Slot2 = ItemBase.Cast( GetInventory().FindAttachment(SP_WoodenPlanks) );
		ItemBase SP_Nails_Slot2 = ItemBase.Cast( GetInventory().FindAttachment(SP_Nails_Slot) );


		if ( (SP_WoodenPlanks_Slot2 && SP_WoodenPlanks_Slot2.GetQuantity() >=  10 ))
		{
			if ((SP_Nails_Slot2 && SP_Nails_Slot2.GetQuantity() >=  40 ))
			{
				return true;
			}
		}
		return false;
	}

	   
   void Sound_Successful()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
            if ( !m_SFX_Succes_2 || !m_SFX_Succes_2.IsSoundPlaying() )
			{
				EffectSound m_SFX_Succes_2 = SEffectManager.PlaySoundOnObject( "SFX_Succes_SoundSet", this );
				m_SFX_Succes_2.SetSoundAutodestroy( true );
			}
		}
    }
	
    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildWoodenPalette);
	}
};