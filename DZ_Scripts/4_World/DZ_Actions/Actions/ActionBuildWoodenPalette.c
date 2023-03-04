class ActionBuildWoodenPaletteCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time = SetCallbackDuration(m_ActionData.m_MainItem);
		m_ActionData.m_ActionComponent = new CAContinuousTime( time );
	}
		
	float SetCallbackDuration( ItemBase item )
	{
		switch( item.Type() )
		{
			case Hammer:
				return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
			default:
				return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
		}
		return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
	}
}

class ActionBuildWoodenPalette: ActionContinuousBase
{
	void ActionBuildWoodenPalette()
	{
		m_CallbackClass = ActionBuildWoodenPaletteCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#build";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			SP_Wooden_Palette_Kit_Deployed m_SP_Wooden_Palette_Kit_Deployed = SP_Wooden_Palette_Kit_Deployed.Cast( target_object );
			
			if( m_SP_Wooden_Palette_Kit_Deployed ) 
			{	
				if (m_SP_Wooden_Palette_Kit_Deployed.CheckSlotsAvailables())
				{
					return true;
				}
			}
			return false;
		}
		return false;
	}

    override void OnFinishProgressServer( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
        vector pos = targetObject.GetPosition();
	
		SP_Wooden_Palette_Kit_Deployed m_SP_Wooden_Palette_Kit_Deployed = SP_Wooden_Palette_Kit_Deployed.Cast( action_data.m_Target.GetObject() );
		
		if (m_SP_Wooden_Palette_Kit_Deployed)
		{			
			m_SP_Wooden_Palette_Kit_Deployed.Delete();
			m_SP_Wooden_Palette_Kit_Deployed = GetGame().CreateObject("SP_Wooden_Palette", pos, false);
			m_SP_Wooden_Palette_Kit_Deployed.SetOrientation( targetObject.GetOrientation() );
			m_SP_Wooden_Palette_Kit_Deployed.Sound_Successful();
		}
	}

	protected void SetBuildingAnimation( ItemBase item )
	{
		switch ( item.Type() )
		{
			case Hammer:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		}
	}
}