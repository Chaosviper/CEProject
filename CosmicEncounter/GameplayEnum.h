
namespace GameplayEnum{
	enum GameboxSet{
		Base,
		CosmicIncursion,
		CosmicConflict,
		CosmicAlliance,
		CosmicStorm,
		CosmicDominion
	};

	enum Color{
		Red,
		Yellow,
		Blue,
		Purple,
		Green,
		Orange,
		Black,
		White
	};

	// BITMASK!
	enum Phases{
		startturn = 0, //  0000000
		regroup = 1,//  0000001
		destiny = 2, //  0000010
		launch = 4,//  0000100
		alliance = 8,//  0001000
		planning = 16,//  0010000
		reveal = 32,//  0100000
		resolution = 64,//  1000000
		allphase = 127 // 1111111
	};

	// BITMASK!
	enum PlayerRole{
		Attack = 1, // 0001
		Defense = 2, // 0010
		MainPlayer = 3, // 0011
		AttackAlly = 4, // 0100
		DefenseAlly = 8, // 1000
		Ally = 12, // 1100
		AnyPlayer = 15 // 1111
	};
}