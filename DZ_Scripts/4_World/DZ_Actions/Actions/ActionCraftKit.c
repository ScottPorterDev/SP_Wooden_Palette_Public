class ActionCraftKitCB : ActionContinuousBaseCB
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
			case Rope:
				return UATimeSpent.DEFAULT_DEPLOY ;

            case WoodenStick:
			return UATimeSpent.DEFAULT_DEPLOY ;

			default:
				return UATimeSpent.DEFAULT_DEPLOY ;
		}
		return UATimeSpent.DEFAULT_DEPLOY ;
	}
}

class ActionCraftKit: ActionContinuousBase
{
	void ActionCraftKit()
	{
		m_CallbackClass = ActionCraftKitCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;

		m_Text = "Make Pallet Storage";
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
			WoodenStick m_SP_WoodenStick = WoodenStick.Cast( target_object );
            Rope m_SP_Rope = Rope.Cast( target_object );
			
			if( m_SP_WoodenStick && m_SP_WoodenStick.GetQuantity() >= 4 ) 
			{	
				return true;
			}
            
            if( m_SP_Rope ) 
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
	
		WoodenStick m_SP_WoodenStick = WoodenStick.Cast( action_data.m_Target.GetObject() );
        Rope m_SP_Rope = Rope.Cast( action_data.m_Target.GetObject() );
        
        PlayerBase m_Player = PlayerBase.Cast( GetGame().GetPlayer() );
        ItemBase itemInHand = m_Player.GetItemInHands();
		
		if (m_SP_WoodenStick)
		{			
			m_SP_WoodenStick.Delete();
			m_SP_WoodenStick = GetGame().CreateObject("SP_Wooden_Palette_Kit", pos, false);
			m_SP_WoodenStick.SetOrientation( targetObject.GetOrientation() );
		}

        if (m_SP_Rope)
		{			
			m_SP_Rope.Delete();
			m_SP_Rope = GetGame().CreateObject("SP_Wooden_Palette_Kit", pos, false);
			m_SP_Rope.SetOrientation( targetObject.GetOrientation() );
		}

        if(itemInHand)
        {
            itemInHand.Delete();
        }
	}

	protected void SetBuildingAnimation( ItemBase item )
	{
		switch ( item.Type() )
		{
			case Rope:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
				break;
            case WoodenStick:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		}
	}
}