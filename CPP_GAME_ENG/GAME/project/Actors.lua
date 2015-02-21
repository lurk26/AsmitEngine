

Setting = {
	MaxZombies = 10,
	MaxChickens = 10,
}


Actors = 
{
	{
		name = "Joe",
        controller = "RandomMoveAI",
		class = "Chicken",
		position = { 20.0, 30.0, 40.0 },
		max_velocity = 100.0,
        texture = "image/game_guy.bmp",
	} ,
	{
		name = "Inky",
		class = "Monster",
        controller = "RandomMoveAI",
        position = { 10.0, 10.0, 10.0 },
		max_velocity = 110.0,
        texture = "image/game_enemy.bmp",
	} ,
	{
		name = "Binky",
		class = "Monster",
        controller = "RandomMoveAI",
        position = { 17.0, 5.0, 5.0 },
		max_velocity = 200.0,
        texture = "image/game_enemy.bmp",
	} ,
	{
		name = "Clyde",
		class = "Monster",
        controller = "RandomMoveAI",
        position = { 40.0, 50.0, 10.0 },
		max_velocity = 100.0,
        texture = "image/game_enemy.bmp",
	}
}