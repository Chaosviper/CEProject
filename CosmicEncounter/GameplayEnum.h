
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
		Attack = 1, // 00001
		Defense = 2, // 00010
		MainPlayer = 3, // 00011
		AttackAlly = 4, // 00100
		DefenseAlly = 8, // 01000
		Ally = 12, // 01100
		None = 16, // 10000 (in logic &, it's true only if confronted with "AnyPlayer")
		AnyPlayer = 31 // 11111
	};
}