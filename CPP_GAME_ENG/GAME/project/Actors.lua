

Setting = {
	MaxZombies = 10,
	MaxChickens = 10,
}


Actors = 
{
	{
		name = "Joe",
        controller = "PlayerController",
		class = "Chicken",
		position = { 20.0, 30.0, 0.0 },
		max_velocity = 100.0,
        texture = "image/game_guy.bmp",
	} ,
	{
		name = "Inky",
		class = "Monster",
        controller = "RandomMoveAI",
        position = { 10.0, 10.0, 0.0 },
		max_velocity = 110.0,
        texture = "image/game_enemy.bmp",
	} 
	
}