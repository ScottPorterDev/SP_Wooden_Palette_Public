class SP_Wooden_Palette_Kit extends KitBase
{	
	protected Object								SP_Wooden_Palette_Kit1;
	
	void SP_Wooden_Palette_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	
	override void EEInit()
	{
		super.EEInit();
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
	}	
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
				
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
    }
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );
		
		PlayerBase pb = PlayerBase.Cast( player );
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			vector newPosition = player_base.GetLocalProjectionPosition();
			vector newOrientation = player_base.GetLocalProjectionOrientation();
				
			SP_Wooden_Palette_Kit1 = GetGame().CreateObject("SP_Wooden_Palette_Kit_Deployed", pb.GetLocalProjectionPosition(), false );
			SP_Wooden_Palette_Kit1.SetPosition( position );
			SP_Wooden_Palette_Kit1.SetOrientation( orientation );
		}	
		
		SetIsDeploySound( true );
		SetLifetime(3888000);
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}

	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		SpawnEntityOnGroundPos("Hammer", GetPosition());

		for (int i0 = 0; i0 < 1; i0++)
		{
			SpawnEntityOnGroundPos("WoodenPlank", GetPosition());
		}
			
		for (int i2 = 0; i2 < 1; i2++)
		{
			SpawnEntityOnGroundPos("Nail", GetPosition());
		}	
	}
}