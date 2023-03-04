modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionBuildWoodenPalette);
        actions.Insert(ActionDestroyWoodeenPalette);
        actions.Insert(ActionCraftKit);
    }
};