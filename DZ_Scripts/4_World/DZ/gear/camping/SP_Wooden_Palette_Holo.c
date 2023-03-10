modded class Hologram
{	
	ItemBase FadedCollision()
	{
		vector center;
		vector relative_ofset;
		vector absolute_ofset = "0 0.01 0"; 
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(SP_Wooden_Palette) )
				{
					SP_Wooden_Palette SP = SP_Wooden_Palette.Cast(obj_collided);
					return SP;
				}
			}
		}
		return null;
	}

	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		
		if (item_in_hands.IsInherited(SP_Wooden_Palette_Kit))
			return "SP_Wooden_Palette_Kit_Deployed";

		return super.ProjectionBasedOnParent();
	}
    override EntityAI PlaceEntity( EntityAI entity_for_placing )
    {    
        ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );
    
        if ( item_in_hands && item_in_hands.CanMakeGardenplot() )
        {
            Class.CastTo(entity_for_placing, GetGame().CreateObject( m_Projection.GetType(), m_Projection.GetPosition() ));
        }
            
        if( entity_for_placing.CanAffectPathgraph() )
        {        
            entity_for_placing.SetAffectPathgraph( true, false );
            
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, entity_for_placing);
        }
        
        return entity_for_placing;
    } 

    override void EvaluateCollision(ItemBase action_item = NULL )
    {
		ItemBase m_Projection = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		ItemBase fortfloor = FadedCollision();
		
        if ( m_Projection.IsInherited(SP_Wooden_Palette_Kit))
        {
            SetIsColliding(false);
            return;
        }
		return;
		
        super.EvaluateCollision(action_item);
    }
}