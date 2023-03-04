class ActionDestroyWoodeenPaletteCB : ActionContinuousBaseCB
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
			case WoodAxe:
				return UATimeSpent.BASEBUILDING_DECONSTRUCT_SLOW;
			default:
				return UATimeSpent.BASEBUILDING_DECONSTRUCT_SLOW;
		}
        return UATimeSpent.BASEBUILDING_DECONSTRUCT_SLOW;
	}
}

class ActionDestroyWoodeenPalette: ActionContinuousBase
{
	void ActionDestroyWoodeenPalette()
	{
		m_CallbackClass = ActionDestroyWoodeenPaletteCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;	
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#dismantle";
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
			SP_Wooden_Palette SPWoodenPalette = SP_Wooden_Palette.Cast( target_object );
			
			if( SPWoodenPalette && SPWoodenPalette.CheckItemsOrAttachements() ) 
			{	
				return true;
			}
			return false;
		}
		return false;
	}

    override void OnFinishProgressServer( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
        vector pos = targetObject.GetPosition();
	
		SP_Wooden_Palette SPWoodenPalette = SP_Wooden_Palette.Cast( action_data.m_Target.GetObject() );
        Nail SP_Nail = Nail.Cast( action_data.m_Target.GetObject() );
        WoodenPlank SP_WP = WoodenPlank.Cast( action_data.m_Target.GetObject() );
       
		
		if (SPWoodenPalette)
		{			
			//Delete Hologram
			SPWoodenPalette.Delete();

			//Orientation
            SP_WP.SetOrientation( targetObject.GetOrientation() );
			SP_Nail.SetOrientation( targetObject.GetOrientation() );

			//Create Object
			SP_Nail = GetGame().CreateObject("Nail", pos, false);
			SP_WP = GetGame().CreateObject("WoodenPlank", pos, false);

			//Quantity Modified
			SP_Nail.AddQuantity(-40);
			SP_WP.AddQuantity(-5);

			SPWoodenPalette.Sound_Successful();
		}
	}

	protected void SetBuildingAnimation( ItemBase item )
	{
		switch ( item.Type() )
		{
			case WoodAxe:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		}
	}
}