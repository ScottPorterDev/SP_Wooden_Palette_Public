class SP_Wooden_Palette extends Inventory_Base
{
	//Sounds
	ref protected EffectSound 	m_SFX_Succes;

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

	bool CheckItemsOrAttachements()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}

	void Sound_Successful()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
            if ( !m_SFX_Succes || !m_SFX_Succes.IsSoundPlaying() )
			{
				EffectSound m_SFX_Succes = SEffectManager.PlaySoundOnObject( "SFX_Succes_SoundSet", this );
				m_SFX_Succes.SetSoundAutodestroy( true );
			}
		}
    }

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDestroyWoodeenPalette);
	}
}